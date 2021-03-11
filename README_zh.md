# 模块介绍<a name="ZH-CN_TOPIC_0000001078530726"></a>

-   [简介](#section469617221261)
-   [架构](#section15884114210197)
-   [目录](#section1464106163817)

## 简介<a name="section469617221261"></a>

itrustee\_ree\_lite组件提供了一套用于和华为自研TEEOS交互的富运行环境（REE）接口组件，包括驱动（tzdriver）、libteec（应用接口库）、teecd（agent服务），其中libteec满足Globalplatform 标准，可提供CA（ClientApp）标准的访问接口。

## 架构<a name="section15884114210197"></a>

itrustee\_ree\_lite组件结构：

![](figures/zh-cn_image_0000001078211160.png)

-   tzdriver：驱动用于ree/tee切换、通讯，提供应用层访问的设备节点。

-   libteec: 提供CA标准GP接口，用于访问设备节点、建立与TEE的通讯会话。

-   teecd：提供agent（代理服务），帮助TEEOS实现文件操作等代理服务。

## 目录<a name="section1464106163817"></a>

**表 1**  itrustee\_ree\_lite源代码目录结构

<a name="table2977131081412"></a>
<table><thead align="left"><tr id="row7977610131417"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p18792459121314"><a name="p18792459121314"></a><a name="p18792459121314"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p77921459191317"><a name="p77921459191317"></a><a name="p77921459191317"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row17977171010144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1836912441194"><a name="p1836912441194"></a><a name="p1836912441194"></a>device/hisilicon/itrustee/itrustee_ree_lite/frameworks/libteec</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p2549609105"><a name="p2549609105"></a><a name="p2549609105"></a>libteec组件的实现代码</p>
</td>
</tr>
<tr id="row6978161091412"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p64006181102"><a name="p64006181102"></a><a name="p64006181102"></a>device/hisilicon/itrustee/itrustee_ree_lite/interfaces/innerkits/libteec</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p7456843192018"><a name="p7456843192018"></a><a name="p7456843192018"></a>libteec组件的接口定义</p>
</td>
</tr>
<tr id="row6978201031415"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1978910485104"><a name="p1978910485104"></a><a name="p1978910485104"></a>device/hisilicon/itrustee/itrustee_ree_lite/services/teecd</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1059035912204"><a name="p1059035912204"></a><a name="p1059035912204"></a>teecd组件的实现代码</p>
</td>
</tr>
<tr id="row1897841071415"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p182586363119"><a name="p182586363119"></a><a name="p182586363119"></a>drivers/liteos/tzdriver/</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p19278126102113"><a name="p19278126102113"></a><a name="p19278126102113"></a>tzdriver驱动的实现代码</p>
</td>
</tr>
</tbody>
</table>

