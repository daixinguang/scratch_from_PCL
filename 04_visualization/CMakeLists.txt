cmake_minimum_required(VERSION 3.12)
cmake_policy(SET CMP0074 NEW)
cmake_policy(SET CMP0167 OLD)

project(pcl_visualization)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 加载PCL，依赖 visualization / io / common
find_package(PCL REQUIRED COMPONENTS
    common
    io
    visualization
)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# 编译目标
add_executable(01_simple_view      ${CMAKE_CURRENT_SOURCE_DIR}/01_simple_view.cpp)
add_executable(02_rgb_view          ${CMAKE_CURRENT_SOURCE_DIR}/02_rgb_view.cpp)
add_executable(03_multi_cloud_view  ${CMAKE_CURRENT_SOURCE_DIR}/03_multi_cloud_view.cpp)
add_executable(04_view_control     ${CMAKE_CURRENT_SOURCE_DIR}/04_view_control.cpp)

# 链接库
target_link_libraries(01_simple_view      ${PCL_LIBRARIES})
target_link_libraries(02_rgb_view          ${PCL_LIBRARIES})
target_link_libraries(03_multi_cloud_view  ${PCL_LIBRARIES})
target_link_libraries(04_view_control     ${PCL_LIBRARIES})