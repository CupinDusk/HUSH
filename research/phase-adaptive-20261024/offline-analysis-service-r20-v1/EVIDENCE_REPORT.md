# R20：服务上界与离线分析规模补证

仅本机读取并复用原模型；未访问服务器、未改稿件、未改旧证据。所有结果存于本目录。

## 可直接进入正文的离线规模结果

1611 个候选的定义是 **255×4 +591**：固定载入 1–255 各配四个免费边界 flush 子集（空、{1}、{2}、{1,2}），共1020；阶段族是 `{1,4,16,32,64,254,255}³ ∪ {(k,k,k):1≤k≤255}` 去重得到591。后者内部去重；不跨固定/阶段族合并，因为阶段实现仍要付两次 marker 成本，即使载入未变化。

纯静态界评估共 **1611×3=4833** 次 `analyze` 调用、**438516** 次事件访问，最多跟踪8个专用接收块。三条输入路径为q=2/4/8，分别19/37/73次共享读；固定路径42/78/150个事件，阶段路径44/80/152个事件（增加两个helper compute事件）。没有有限LRU栈或CFG状态合并。

在 Intel Core i9-14900HX、24物理核/32逻辑线程、约31.6GiB内存、Windows11 build26200、64位Python3.12.14 `-B -X utf8` 上，单进程串行调用的三次 wall time 为 **0.169350 /0.170360 /0.170051秒，中位0.170051秒**。绝对进程峰值工作集最大 **22.58594MiB**，峰值private commit最大14.45313MiB。内存包括Python运行时、原模型、准备好的输入和4833条保留结果，不含随后读取预期结果的内存；不是声称分析器独占增量仅22.6MiB。

计时窗包括原界转移、路径参数切换、C求和、结果构建；不含启动/import、路径/候选生成、模拟、原生实验、训练makespan选择、验证/序列化。`m.simulate` 被替换为必定抛错的函数，排除混入执行模拟。该结果应称为 **bound evaluation / admission analysis**，不能写成全套训练选择仅0.17秒。

三次各有48330项逐字段检查，与原R18冻结的4833条路径界、命中分类、控制次数及可行性全部一致；仍为1个固定/30个阶段候选满足共同预算。初始直读旧位置的三次测量也保留为run1/2/3；最后可携预期ZIP版本为run4/5/6，正文采用后者。旧结果未覆写。

一个可复算的输入实例：q=2的完整BSQ接收路径为2次bootstrap读、16次steady读、1次quiet读，前18次各有1cycle计算，quiet含512cycle；两个marker各8cycle，故C=546。载入 `(∞,∞,4)` 在P=2时产生H=17,U=2,S=1，W=546+17×1+2×71+1=706；其他两路径882/1234，对共同预算1249均可行。C来自所供指令路径与给定上界，不是自动处理器WCET推导。

英文建议（可压缩）：

> The common search comprises 255 fixed loads × four free flush subsets plus 591 deduplicated phase vectors. Its 4,833 path-bound evaluations visit 438,516 events and take a median 0.170 s with 22.6 MiB peak process memory in Python 3.12 on an i9-14900HX/Windows 11; execution-driven training is excluded.

直接枚举随候选数、路径事件数、跟踪块数增长；当前vector-expiry实现约为 `O(Ncandidate × Σpath(Nevent × Nblock))`，有限LRU还有栈操作。D个候选载入、p段的一般枚举为D^p；此处是受限候选域和显式有界路径的实例，不能据三路径实验宣称无路径爆炸。

## 完整离线训练选择耗时（包括执行模拟）

根据父任务补充要求，对原来的完整evaluate/selection链又作三次新进程计时，全部4833条原始执行记录逐项等于R18冻结ALL_CANDIDATES.json。计时包含预算推导、候选生成、路径生成、全部 `analyze+simulate`、max-path准入和min训练joint选择；不含startup/import、协议IO、验证/序列化、heldout或native。

三次时间 **5.249543 /5.236794 /5.255419秒，中位5.249543秒**；绝对Python进程峰值工作集最大 **25.140625MiB**，peak private commit17.199219MiB。平台同上。固定与阶段共同选择仍分别为 `(∞,∞,∞)` 与 `(∞,∞,4)`，最坏训练J3446→3266。详见FULL_SELECTION_SUMMARY.json。

建议正文主报完整选择 **5.25s、25.2MiB**（内存向上取0.1MiB），0.170s纯bound只是成本分解；不要把0.17s写成包括min-training-J搜索的总耗时：

> The 1,611-candidate common search (255 fixed loads × four flush subsets plus 591 phase vectors) performs 4,833 training executions in 5.25 s with 25.2 MiB peak process memory (Python 3.12, i9-14900HX); bound evaluation alone takes 0.170 s.

## 71cycle服务上界：两个分支，不叠加

模型顺序：配置commit → WU/fill/private完成 → decrement → buffered response → writer/receiver issue → bus grant。每核仅一笔outstanding。writer的private与WU互斥。待队列中的miss阻止新private admission；miss获grant时设置sharing，保持到fill。读outstanding时不能发下一phase write。

### A. 普通miss：保守71包络

以miss issue为相对0：

| 区间/边界 | 最迟动作 | 理由 |
|---|---|---|
| [0,1] | 之前准入的private store完成 | 最多一笔，1cycle；pending miss阻止后续private准入 |
| [1,11] | 最多一笔其他客户端WU完成 | 两客户端非抢占round-robin；不能无限插队 |
| [11,71] | miss自己的60cycle服务、fill | 获grant时保留sharing；无后续phase事务 |

这是一条 **分段最迟完成包络**，并不证明所有最坏分段在一个可达运行中同时取等。既有实际trace为：issue0、private结束/grant1、fill61（61cycle）；另一个实际trace为issue61、WU结束/grant71、fill131（70cycle）。这次重新运行原模型得到同一逐事件JSON。**尚无71cycle可达见证，不把71写成观测最大值或紧界。**

### B. 配置撞上即将完成的WU：61，亦被71覆盖

冻结例子有绝对周期：61 grant WU，原定71完成；70 issue配置；71配置commit、将WU完成推迟到72；同一71 issue miss；72 WU完成并grant miss；132 fill。miss服务为132−71=**61cycle**。

以该miss issue为相对0：WU只剩配置造成的[0,1]残留，随后miss[1,61]；它不再有完整10cycle WU可加。WU在flight时writer已outstanding，因此不能同时有old private store。该writer待WU完成后也不能在待队列miss前准入新private。配置事务本身的1cycle在issue之前，已由S·Lsw计入，不能再次完整计入读服务。

因此 `Lm=max(1+10+60,1+60)=71` 是清楚的保守上界；**不是** `1private+10WU+1config+60=72`。配置残留分支不能与private/full-WU分支拼起来。

`SERVICE_CASE_CHECK.json` 验证22个普通算术包络与1个配置分支、保守最大71/61，并逐字节数据比较新跑trace与旧期望；这是gate前提下的case arithmetic和三个定向执行，**不是穷尽可达状态证明**。没有发现与71上界不一致的实证。英文建议：

> An ordinary miss waits at most one admitted private-store cycle, one ten-cycle WU and its 60-cycle service. A configuration collision instead leaves only one cycle of a finishing WU; the single outstanding writer cannot also hold a private store. Thus Lm=max(1+10+60,1+60)=71.

若空间允许括号给一条实测周期 `(issue71,WU72,fill132)`，可直接回答审稿时间线问题。

## 复跑

- `python -B -X utf8 profile_bound.py 7`：只做纯界评估，48330项检查；Windows内存计数API为本机专用。
- `python -B -X utf8 probe_service71.py`，再 `python -B -X utf8 check_service_cases.py`：三个原模型trace及互斥分支检查。
- `PROFILE_SUMMARY.json`、`BOUND_PROFILE_4/5/6.json` 是正文计时来源。

原模型SHA256：6270a7fa1c79a81dab99f9712e170c60c1ded14dd5052f3b987ba421a1b99e10。输入与旧证据绑定见INPUT_BINDING.json。父任务可将本目录作为最小复现附件；prepare_inputs.py仅为构造绑定/预期值的开发入口，正常复跑不需要旧目录。
