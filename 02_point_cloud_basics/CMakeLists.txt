cmake_minimum_required(VERSION 3.12)
cmake_policy(SET CMP0074 NEW)
cmake_policy(SET CMP0167 OLD)

project(pointcloud_basics)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 找到 PCL
find_package(PCL REQUIRED COMPONENTS
    common
    io
    filters
    visualization
)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# 生成可执行文件
add_executable(01_create_cloud        ${CMAKE_CURRENT_SOURCE_DIR}/01_create_cloud.cpp)
add_executable(02_visit_points        ${CMAKE_CURRENT_SOURCE_DIR}/02_visit_points.cpp)
add_executable(03_modify_points       ${CMAKE_CURRENT_SOURCE_DIR}/03_modify_points.cpp)
add_executable(04_cloud_copy          ${CMAKE_CURRENT_SOURCE_DIR}/04_cloud_copy.cpp)
add_executable(05_pointcloud_ptr      ${CMAKE_CURRENT_SOURCE_DIR}/05_pointcloud_ptr.cpp)
add_executable(05_pointcloud_ptr2     ${CMAKE_CURRENT_SOURCE_DIR}/05_pointcloud_ptr2.cpp)

# 链接 PCL
target_link_libraries(01_create_cloud      ${PCL_LIBRARIES})
target_link_libraries(02_visit_points      ${PCL_LIBRARIES})
target_link_libraries(03_modify_points     ${PCL_LIBRARIES})
target_link_libraries(04_cloud_copy        ${PCL_LIBRARIES})
target_link_libraries(05_pointcloud_ptr    ${PCL_LIBRARIES})
target_link_libraries(05_pointcloud_ptr2   ${PCL_LIBRARIES})