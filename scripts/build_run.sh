#!/bin/bash

# 清理旧构建目录
echo "===== 清理旧 build 目录 ====="
rm -rf build

# 创建并进入 build
echo "===== 创建新 build 目录 ====="
mkdir build
cd build || exit 1

# 执行 CMake + 编译
echo "===== 执行 CMake 配置 ====="
cmake ..

echo -e "\n===== 开始编译 ====="
make

echo -e "\n✅ 编译完成！"

cd ..