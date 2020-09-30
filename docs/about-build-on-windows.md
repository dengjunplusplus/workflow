# Windows下编译

## 安装OpenSSL

### Windows下安装OpenSSL库包括以下几种方式

* 下载源码自行编译
* 下载二进制文件或安装包
* 通过Chocolatey安装
* 通过vcpkg安装

### 下载源码自行编译

可以去官网或者GitHub仓库进行代码下载，编译过程参见源码中的编译文档

* [openssl官网](https://www.openssl.org/)
* [github仓库](https://github.com/openssl/openssl)

### 下载二进制文件或安装包

请自行通过搜索引擎进行搜索，将文件解压到特定目录，或者运行安装包
[二进制下载](https://wiki.openssl.org/index.php/Binaries)

### 通过Chocolatey安装

Chocolatey是一个 Windows下的包管理器，类似于 Linux 下的 apt-get或 yum，可以方便的进行软件包的安装，Chocolatey的安装参考[Chocolatey官网](https://www.chocolatey.org/)
安装完Chocolatey后，执行下面的命令，即可安装OpenSSL
```powershell
choco install openssl
```

### 通过vcpkg安装

vcpkg是一个Windows下的C++包管理工具，它极大地简化了第三方库的配置与安装，vcpkg的安装请参考微软官方文档[VCPKG官方文档](https://docs.microsoft.com/zh-cn/cpp/build/vcpkg?view=vs-2019)
安装完vcpkg后，执行下面的命令，即可安装OpenSSL
```powershell
vcpkg install openssl
```

## 编译workflow库

通过源码编译或者下载二进制进行openssl安装的，在编译过程中可以通过指定OPENSSL_ROOT_DIR的方式进行编译，在workflow根目录下执行下面的命令

```powershell
cmake -B [build directory] -S . -DOPENSSL_ROOT_DIR=[openssl directory]
```

通过安装包安装或者通过Chocolatey安装openssl的，无需指定openssl的路径，在workflow根目录下执行下面的命令

```powershell
cmake -B [build directory] -S .
```

通过vcpkg安装openssl的，需要指定CMAKE_TOOLCHAIN_FILE的路径

```powershell
 cmake -B [build directory] -S . -DCMAKE_TOOLCHAIN_FILE=[vcpkg.cmake directory]
```

[openssl directory] : openssl目录，请自行替换
[build directory] : 构建目录，一般使用build目录
[vcpkg.cmake directory] : 一般为vcpkg根目录\scripts\buildsystems\vcpkg.cmake

执行完成后，在[build directory]下会生成workflow.sln，可以用VS打开进行编译，或执行cmake命令进行编译

```powershell
cmake --build [build directory]
```
