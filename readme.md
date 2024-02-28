# 说明

本项目遵守MIT协议，可以宽松的用于非商用和商用目的，但本项目主要是为了帮助大家学习和理解图片处理的底层原理。工程通过cmake组织，可以在Linux和windows下编译运行。项目文件说明如下：

- CMakeLists.txt为cmake组织文件
- src文件夹为源代码
- src/core文件夹为bmp类和相关的操作 是各个应用的公用代码
- Test.cpp为单元测试
- Tool.cpp为应用工具
- Draw.cpp为画图实例
- bmp文件夹存放图片

需要增加自己应用的同学，可以修改CMakeLists.txt添加新的目标，也可以直接修改Tool.cpp。

视频教程如下，有兴趣的同学可以学习：

【手搓开源跨平台 C++ BMP 图片库（1）图片格式、图片读写】 https://www.bilibili.com/video/BV1s6421g7ya/

## Windows编译

windows通过vscode + Mingw方式开发，可以通过下面链接学习编译方法。

【Windows C/C++ 开发环境选择及vscode + Mingw安装】 https://www.bilibili.com/video/BV1ub4y1N7G4/

## Linux编译

进入项目根目录，输入以下命令：

`cmake -S . -B build`

`cd build`

`make`

## 测试运行

进入项目根目录，输入以下命令：

`cd build`

`.\Test.exe`

运行测试之后，bmp/test文件夹下会生成很多bmp图片。

## 编写自己应用

编写自己应用需要以下几步：

在src目录下新建自己的App.cpp文件

在CMakeLists.txt文件的生成程序下增加以下代码：

```
add_executable(App ${CORE_SRC} ./src/App.cpp)
```

这样编译完成后，build目录里会多一个App.exe。

进入项目根目录，输入以下命令：

`cd build`

`.\App.exe`

就运行了自己添加的应用。

以上只是建议，cmake熟练的同学可以随意修改。

## 调试代码

core目录里的代码是各个应用共用的，其他在src第一层目录里的代码是各个应用独有的。调试是以应用为基础单位进行的，所以需要调试哪个应用，就要把.vscode/launch.json里的program项修改成自己需要调试的应用，如下：

```
"program": "${workspaceFolder}/build/Test.exe",
```

改成

```
"program": "${workspaceFolder}/build/App.exe",
```

然后，点击vscode左侧窗口里的run and debug，再点击子窗口上面的start debugging 三角图标，开始调试。点击cmake tools的debug图标触发的调试界面，不会响应.vscode/launch.json的内容修改，不推荐用这种方式触发调试。
