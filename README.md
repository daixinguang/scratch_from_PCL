# scratch_from_PCL
从零开始学习PCL

整体设计思路：

1. 先搭建环境，配置好C++环境，和PCL包的安装。
2. 跳过基本语法，重点介绍C++必备高阶语法（适配PCL开发）。
3. 介绍点云核心概念，和点云的一些常用操作。
4. 从PCL基础IO、可视化到滤波、分割、特征、配准递进，全程遵循「语法基础→原理理解→代码实操→项目落地」闭环，无知识点跳跃，适配纯零基础学习者。

前置说明：所有章节均配套：知识点讲解 + 极简Demo代码 + 逐行注释 + 常见报错排查，学完即会用，拒绝纸上谈兵。


## 0. 环境配置

当前MACOS系统，使用conda创建专用环境，安装PCL，编译器使用Clang，C++标准为C++17。

```sh
conda create -n pcl_env
conda activate pcl_env
conda install -c conda-forge pcl
conda install -c conda-forge cmake
conda install -c conda-forge eigen
conda install -c conda-forge boost
conda install -c conda-forge vtk
```

VSCode配置C++开发环境，安装C/C++插件，配置includePath和compilerPath。

```json
{
    "configurations": [
        {
            "name": "Mac",
            "includePath": [
                "${workspaceFolder}/**",
                "/opt/homebrew/include",
                "/opt/homebrew/include/pcl-1.15",
                "/opt/homebrew/include/boost",
                "/opt/homebrew/include/eigen3",
                "/opt/homebrew/include/vtk-9.0"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/clang",
            "cStandard": "c17",
            "cppStandard": "c++17ma",
            "intelliSenseMode": "macos-clang-arm64"
        }
    ],
    "version": 4
}
```

目录结构如下：

```sh
scratch_from_PCL/
├── README.md                    # 学习进度、目录说明、环境配置指南
├── CMakeLists.txt               # 顶层统一编译配置
├── build/                       # CMake构建目录，存放编译生成的文件
├── cmake/
│   └── FindPCL.cmake            # PCL库查找模块
├── XX_XXXX/                     # 每章一个目录，包含CMakeLists.txt和Demo代码
│   └── CMakeLists.txt           # 本章编译配置，在顶层CMake中通过add_subdirectory引入。
│   └── xxx.cpp                  # 本章Demo代码
├── data/                        # 测试点云数据存放
```

> Q:为什么要在根目录用build目录存放编译文件，而不是直接在源代码目录编译？
> A: 这种做法叫做Out-of-Source Build（源代码外构建）。
>
> 1. 可以保持源代码目录的整洁，避免编译过程中生成的中间文件和可执行文件混杂在一起，方便管理和清理。
> 2. 可以同时维护多个构建配置（如Debug和Release），只需在不同的build目录中编译即可，无需修改源代码。eg:在build目录下创建子目录，如build/debug和build/release，分别进行不同配置的编译。
> 3. 解决多目录编译缓存冲突、库链接异常、重复编译问题。
> 4. 更符合CMake的推荐实践，许多CMake项目都采用这种结构。

## 1. 章节内容及其对应代码

### 00_cpp_basics：C++基础语法，适配PCL开发的C++高阶语法（命名空间、引用、智能指针等）

- 命名空间：对应 `pcl::`、`pcl::io::`、`pcl::visualization::`
- 引用：PCL 函数参数几乎全用 `const pcl::PointCloud<...>&` 这种引用传递方式，既避免了值传递的性能开销，又保证了函数内部不能修改传入的点云数据。
- vector：`pcl::PointCloud<PointT>::points` 本质就是 `std::vector<PointT>`
- 智能指针：`pcl::PointCloud<PointT>::Ptr` 就是 `std::shared_ptr<pcl::PointCloud<PointT>>`


### 01_env_install：环境安装验证，PCL环境测试代码，常见安装问题排查
暂定目录结构如下：

```sh
scratch_from_PCL/
├── README.md                    # 学习进度、目录说明、环境配置指南
├── CMakeLists.txt               # 顶层总编译配置（入口文件）
├── build/                       # 【唯一编译目录】全局统一构建产物、缓存
├── cmake/
│   └── FindPCL.cmake            # PCL库查找模块
├── 00_cpp_basics/               # 章节子工程（仅源码+子CMake）
│   ├── CMakeLists.txt           # 本章子编译配置
│   ├── 01_namespace_demo.cpp
│   ├── 02_reference_demo.cpp
│   ├── 03_stl_vector.cpp
│   └── 04_smart_ptr.cpp
├── 01_env_install/
│   ├── CMakeLists.txt
│   └── pcl_env_test.cpp
├── 02_pointcloud_base/
├── 03_io_operation/
├── 04_visualization/
├── 05_filter_denoise/
├── 06_normal_feature/
├── 07_segmentation/
├── 08_registration/
├── 09_project_practice/
├── data/                        # 测试点云数据存放
│   ├── test.pcd
│   └── .gitkeep
```

