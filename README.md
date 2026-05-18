# scratch_from_PCL
从零开始学习PCL

暂定目录结构如下：
```sh
scratch_from_PCL/
├── README.md                    # 项目说明、学习进度
├── CMakeLists.txt               # 顶层CMake配置
├── cmake/
│   └── FindPCL.cmake           # PCL查找模块（可选）
├── 01_install_test/            # 第1课：安装与测试
│   ├── CMakeLists.txt
│   └── pcl_test.cpp            # 读取PCD文件并显示
├── 02_point_cloud_basics/      # 第2课：点云基础
│   ├── CMakeLists.txt
│   └── point_structure.cpp     # PointXYZ, Normal, RGB等
├── 03_io_operations/           # 第3课：文件I/O
│   ├── pcd_read_write.cpp
│   └── pcd_generate.cpp        # 生成随机点云
├── 04_visualization/           # 第4课：可视化
│   └── cloud_viewer.cpp
├── 05_filters/                 # 第5课：滤波
│   ├── voxel_grid.cpp          # 体素滤波
│   └── statistical_outlier.cpp # 统计滤波
├── 06_segmentation/            # 第6课：分割
│   └── plane_segmentation.cpp  # RANSAC平面分割
├── 07_features/                # 第7课：特征提取
│   └── normals_estimation.cpp  # 法线估计
├── 08_registration/            # 第8课：配准
│   └── icp_registration.cpp    # ICP配准
├── data/                       # 存放点云数据文件
│   └── .gitkeep
└── scripts/                    # 辅助脚本
    └── install_pcl_ubuntu.sh   # Ubuntu安装脚本
```

