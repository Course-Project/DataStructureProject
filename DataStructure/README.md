Data Structure Project
======================

数据结构课程设计

## 编译

本文件夹下有两份Makefile：

- Makefile
- Makefile for windows

各自使用的场景不一样

#### Makefile

Makefile在Mac/Linux下使用，要求已经安装好g++和i386-mingw32-g++，并配置好PATH环境变量

其中i386-mingw32-g++用于在Mac下交叉编译成exe

使用示例：

```
$ make					// 编译Mac和Win下的可执行文件
$ make win				// 仅编译Win下的可执行文件
$ make mac				// 仅编译Mac下的可执行文件
$ make clean			// 清空所有编译生成的文件，包括可执行文件
```

#### Makefile for windows

该文件在Windows下使用，使用前需将其改名为Makefile，打开Visual Studio命令行工具，并进入该项目文件夹

使用示例：

```
$ nmake					// 编译exe文件
$ nmake clean			// 清空所有编译生成的文件，包括可执行文件
```
