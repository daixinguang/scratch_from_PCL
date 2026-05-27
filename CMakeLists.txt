cmake_minimum_required(VERSION 3.11)
project(PCL_Scratch)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# 查找PCL
# 按需加载PCL指定版本和组件
find_package(PCL 1.14 REQUIRED COMPONENTS
common io visualization filters segmentation features registration)

# 添加头文件路径
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# 每个子目录的CMakeLists.txt会被后续添加
# add_subdirectory(00_cpp_basics)
# add_subdirectory(01_install_test)
# add_subdirectory(02_point_cloud_basics)
# add_subdirectory(03_io_operations)
add_subdirectory(04_visualization)
# ... 逐步取消注释