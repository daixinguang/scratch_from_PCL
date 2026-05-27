cmake_minimum_required(VERSION 3.11)

# 启用新策略，允许 find_package 使用 *_ROOT 变量(上层CMakeLists.txt中find_package(PCL)会赋值PCL_ROOT，
# CMake 3.10 及更早默认旧策略：find_package 不识别 XXX_ROOT 变量
# CMake 3.11 及更高默认新策略：find_package 识别 XXX_ROOT 变量
cmake_policy(SET CMP0074 NEW)


project(test_pcl)
# Cmake内置变量CMAKE_CXX_STANDARD设置C++标准为17
set(CMAKE_CXX_STANDARD 17)
# find_package函数查找PCL库，REQUIRED表示如果找不到库则会报错
find_package(PCL REQUIRED COMPONENTS
common io visualization)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(01_namespace_demo ${CMAKE_CURRENT_SOURCE_DIR}/01_namespace_demo.cpp)
# 不依赖PCL库的Demo不链接PCL库
# target_link_libraries(01_namespace_demo ${PCL_LIBRARIES})
add_executable(02_reference_demo 02_reference_demo.cpp)
add_executable(03_stl_vector 03_stl_vector.cpp)
add_executable(04_smart_ptr 04_smart_ptr.cpp)