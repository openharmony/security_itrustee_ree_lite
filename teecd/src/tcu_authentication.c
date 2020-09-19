/*
 * Copyright (c) 2020 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "tcu_authentication.h"
#include <errno.h> /* for errno */
#include <fcntl.h>
#include <sys/ioctl.h> /* for ioctl */
#include <sys/types.h> /* for open close */
#include <unistd.h>
#include "securec.h"
#include "tc_ns_client.h"
#include "tee_client_type.h"
#include "tee_log.h"
#include "teec_compat.h"

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG            "teec_auth_native"
#define HASH_FILE_MAX_SIZE (16 * 1024)
#define VENDOR_HASH_FILE "/vendor/bin/native_packages.xml"

static bool IsInvalidFilename(const char *path)
{
    if (path == NULL) {
        tloge("filename is invalid ...\n");
        return true;
    }

    /* filter the .. dir in the pname: */
    if (strstr(path, "..") != NULL) {
        tloge("filename should not include .. dir\n");
        return true;
    }

    return false;
}

static int GetFileSize(const char *path)
{
    FILE *fp = NULL;
    int fileSize                = -1;
    char realPath[PATH_MAX + 1] = { 0 };

    if ((path == NULL) || (strlen(path) > PATH_MAX) || IsInvalidFilename(path) ||
        realpath(path, realPath) == NULL)) {
        return fileSize;
    }

    fp = fopen(realPath, "r");
    if (fp == NULL) {
        return fileSize;
    }

    if (fseek(fp, 0L, SEEK_END) == 0) {
        fileSize = (int)ftell(fp);
    }
    fclose(fp);
    fp = NULL;

    return fileSize;
}

static int GetFileInfo(int bufLen, uint8_t *buffer, const char *path)
{
    FILE *fp = NULL;
    int fileSize;
    char realPath[PATH_MAX + 1] = { 0 };

    if ((buffer == NULL) || (path == NULL) || bufLen < sizeof(int) || (strlen(path) > PATH_MAX) ||
        IsInvalidFilename(path) || (realpath(path, realPath) == NULL)) {
        return -1;
    }

    fp = fopen(realPath, "rb");
    if (fp == NULL) {
        tloge("open file failed\n");
        return -1;
    }

    fileSize = (int)fread(buffer, sizeof(char), (unsigned int)bufLen, fp);
    fclose(fp);
    fp = NULL;
    if ((fileSize != bufLen) || (*(unsigned int *)buffer) != fileSize) {
        tloge("read file read number:%d\n", fileSize);
        return -1;
    }
    return 0;
}

static uint8_t *InitTempBuf(int bufLen)
{
    uint8_t *buffer = NULL;

    if ((bufLen <= 0) || (bufLen > HASH_FILE_MAX_SIZE)) {
        tloge("wrong buflen\n");
        return buffer;
    }

    buffer = (uint8_t *)malloc((unsigned int)bufLen);
    if (buffer == NULL) {
        tloge("malloc failed!\n");
        return buffer;
    }

    if (memset_s(buffer, (unsigned int)bufLen, 0, (unsigned int)bufLen) != EOK) {
        tloge("memset failed!\n");
        free(buffer);
        buffer = NULL;
        return buffer;
    }

    return buffer;
}

static uint8_t *ReadXmlFile(const char *xmlFile)
{
    int bufLen;
    uint8_t *buffer = NULL;

    bufLen = GetFileSize(xmlFile);
    buffer = InitTempBuf(bufLen);
    if (buffer == NULL) {
        tloge("init temp buffer failed\n");
        return buffer;
    }

    if (GetFileInfo(bufLen, buffer, xmlFile) != 0) {
        tloge("get xml file info failed\n");
        free(buffer);
        buffer = NULL;
        return buffer;
    }

    return buffer;
}

static int TeeSetNativeCaHash(const char *xmlFlie)
{
    int ret;
    int fd          = -1;
    uint8_t *buffer = NULL;

    buffer = ReadXmlFile(xmlFlie);
    if (buffer == NULL) {
        tloge("read xml file failed\n");
        return fd;
    }

    fd = open(TC_NS_CLIENT_DEV_NAME, O_RDWR);
    if (fd < 0) {
        tloge("Failed to open dev node: %s\n", strerror(errno));
        free(buffer);
        buffer = NULL;
        return -1;
    }

    ret = ioctl(fd, (int)(TC_NS_CLIENT_IOCTL_SET_NATIVE_IDENTITY), buffer);
    free(buffer);
    buffer = NULL;
    close(fd);
    fd = -1;
    if (ret != 0) {
        tloge("ioctl fail %d\n", ret);
    }

    return ret;
}

void TcuAuthentication(void)
{
    TeeSetNativeCaHash(VENDOR_HASH_FILE);
}
