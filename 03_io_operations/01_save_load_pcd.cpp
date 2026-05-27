#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <iostream>

int main()
{
    // 1. 初始化点云智能指针
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    cloud->width = 1000;
    cloud->height = 1;
    cloud->points.resize(cloud->width * cloud->height);

    // 填充随机坐标点
    std::srand(42);
    for (auto& point : cloud->points)
    {
        point.x = static_cast<float>(std::rand()) / RAND_MAX * 10.0f;
        point.y = static_cast<float>(std::rand()) / RAND_MAX * 10.0f;
        point.z = static_cast<float>(std::rand()) / RAND_MAX * 10.0f;
    }

    // 2. 保存 ASCII 格式（文本可读，体积大）
    pcl::io::savePCDFileASCII("./data/ascii_cloud.pcd", *cloud);
    std::cout << "✅ 已保存 ASCII 格式点云: ascii_cloud.pcd" << std::endl;

    // 3. 保存 Binary 格式（二进制，体积小、读写快）
    pcl::io::savePCDFileBinary("./data/binary_cloud.pcd", *cloud);
    std::cout << "✅ 已保存 Binary 格式点云: binary_cloud.pcd" << std::endl;

    // 4. 读取 PCD 文件
    pcl::PointCloud<pcl::PointXYZ>::Ptr loaded_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    if (pcl::io::loadPCDFile<pcl::PointXYZ>("./data/ascii_cloud.pcd", *loaded_cloud) == -1)
    {
        PCL_ERROR("❌ 加载 PCD 文件失败！\n");
        return -1;
    }
    std::cout << "✅ 加载成功，总点数: " << loaded_cloud->size() << std::endl;

    // 简单统计
    float sum_x = 0.0f;
    for (const auto& p : *loaded_cloud)
    {
        sum_x += p.x;
    }
    std::cout << "📊 点云平均 X 坐标: " << sum_x / loaded_cloud->size() << std::endl;

    return 0;
}