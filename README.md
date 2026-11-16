# STM32-Coding-Repository

STM32F103 学习与练习工程集合，包含 HAL 库与标准库（SPL）两套实现，均为 Keil MDK 工程。

## 目录结构

| 目录 | 内容 | 工程数量 |
| --- | --- | --- |
| `HAL/` | HAL 库工程（CubeMX + Keil MDK） | 13 |
| `open/SPL/江协代码复习/` | 标准库复习工程 | 9 |
| `江协课程代码/` | 江协科技教程配套例程（标准库） | 36 |

## 开发环境

- MCU：STM32F103C8T6（部分工程为 STM32F103xB 系列）
- IDE：Keil MDK（uVision 5）
- 库：STM32F10x 标准外设库 / STM32F1 HAL 库

## 使用方法

用 Keil MDK 打开对应工程目录下的 `*.uvprojx` 文件，编译并下载到开发板即可。

- 标准库工程：打开各例程目录下的 `project.uvprojx`
- HAL 工程：打开 `MDK-ARM/` 目录下的 `*.uvprojx`

## 说明

`.gitignore` 已排除 Keil 编译产物（`Objects/`、`Listings/`、`*.o`、`*.axf`、`*.hex`、`*.map` 等）以及个人 IDE 配置，克隆后重新编译即可生成。
