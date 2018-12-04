# 安装 C++ 编译环境

## Windows 10

### [Virtual Studio](https://visualstudio.microsoft.com/zh-hans/vs/)

微软开发的强大的编辑器，可以用来开发包括 C、C++、C#、Python 在内的多种语言的程序。

如果你只对在 Windows 环境下开发感兴趣，并且对自己电脑的性能有足够的信心，那就选择 VS 吧。在[官网](https://visualstudio.microsoft.com/zh-hans/vs/)上下载安装即可。

如果你勾选了 C++ 开发的话，那么安装完成时，你的电脑已经有了 C++ 的编译环境。

### [MinGW](http://www.mingw.org/download/installer)

MinGW 是 “Minimalist GNU for Windows” 的缩写，是 gcc 编译器的 Windows 移植版本，其表现与 Linux 平台下的 gcc 基本一致。因为 OJ 平台与 ACM 比赛平台多为 Linux 系统，使用 MinGW 可以尽量避免因环境不同而造成的莫名 bug。

安装时需要选择安装项，可以将无脑将 Basic Setup 里面的 Package 全部选上。关于其中每一项的具体意义，可以参照[这个博客](https://www.cnblogs.com/yabin/p/6257909.html)。

安装完将 `C:\MinGW\bin` 添加到环境变量中，之后可以 `gcc -v` 查看版本。

### WSL + gcc

WSL 与 gcc 的安装，请参照 [OI-Wiki](https://oi-wiki.org/intro/wsl/)。

WSL 与正常的 Linux 系统还是有区别的（有些命令是无法使用的，比如 `nmap`），但是总体来说还是挺好用的。适用于既想要体验 Linux 系统强大的能力，又无法割舍一些 Windows 上独有的功能（QQ、微信、游戏等）的同学。

## Windows 10 之前的版本

去安装个 Windows 10 吧。如果你认为你机器的性能不足以支持你使用 Windows 10 的话，那么正好可以开始尝试 Linux 了。

我**个人**推荐的发行版是 Ubuntu 稳定版，去[官网](https://www.ubuntu.com/download/desktop)下载就完事了。

## Linux

主流的 Linux 系统都是附带 gcc 编译器的，可以直接使用。
