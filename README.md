# itrustee\_ree\_lite<a name="EN-US_TOPIC_0000001078530726"></a>

-   [Introduction](#section469617221261)
-   [Architecture](#section15884114210197)
-   [Directory Structure](#section1464106163817)

## Introduction<a name="section469617221261"></a>

The itrustee\_ree\_lite module provides a set of rich execution environment \(REE\) API components for interacting with Huawei-developed TEEOS, including tzdriver \(driver\), libteec \(API library\), and teecd \(agent service\). libteec meets the GlobalPlatform \(GP\) standards and provides ClientApp \(CA\) APIs.

## Architecture<a name="section15884114210197"></a>

The following figure shows the itrustee\_ree\_lite architecture.

![](figures/en-us_image_0000001078211160.png)

-   tzdriver: enables switching and communication between the REE and trusted execution environment \(TEE\) and provides device nodes that can be accessed from the application layer.

-   libteec: provides CA GP APIs for accessing device nodes and establishing communication sessions with the TEE.

-   teecd: provides agent services for TEEOS, such as file operations.

## Directory Structure<a name="section1464106163817"></a>

**Table  1**  Directory structure of itrustee\_ree\_lite

<a name="table2977131081412"></a>
<table><thead align="left"><tr id="row7977610131417"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p18792459121314"><a name="p18792459121314"></a><a name="p18792459121314"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p77921459191317"><a name="p77921459191317"></a><a name="p77921459191317"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row17977171010144"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1836912441194"><a name="p1836912441194"></a><a name="p1836912441194"></a>device/hisilicon/itrustee/itrustee_ree_lite/frameworks/libteec</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p2549609105"><a name="p2549609105"></a><a name="p2549609105"></a>Implementation code of libteec</p>
</td>
</tr>
<tr id="row6978161091412"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p64006181102"><a name="p64006181102"></a><a name="p64006181102"></a>device/hisilicon/itrustee/itrustee_ree_lite/interfaces/innerkits/libteec</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p7456843192018"><a name="p7456843192018"></a><a name="p7456843192018"></a>APIs of libteec</p>
</td>
</tr>
<tr id="row6978201031415"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1978910485104"><a name="p1978910485104"></a><a name="p1978910485104"></a>device/hisilicon/itrustee/itrustee_ree_lite/services/teecd</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1059035912204"><a name="p1059035912204"></a><a name="p1059035912204"></a>Implementation code of teecd</p>
</td>
</tr>
<tr id="row1897841071415"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p182586363119"><a name="p182586363119"></a><a name="p182586363119"></a>drivers/liteos/tzdriver/</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p19278126102113"><a name="p19278126102113"></a><a name="p19278126102113"></a>Implementation code of tzdriver</p>
</td>
</tr>
</tbody>
</table>

