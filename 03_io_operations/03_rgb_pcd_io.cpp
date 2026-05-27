#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <iostream>

int main()
{
    // 彩色点云类型：PointXYZRGB
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr rgb_cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    rgb_cloud->width = 5;
    rgb_cloud->height = 1;
    rgb_cloud->resize(rgb_cloud->width * rgb_cloud->height);

    // 填充坐标 + 颜色
    for (auto& p : *rgb_cloud)
    {
        p.x = rand() % 10;
        p.y = rand() % 10;
        p.z = rand() % 10;
        p.r = 255;  // 红色
        p.g = 0;
        p.b = 0;
    }

    // 保存彩色PCD
    pcl::io::savePCDFileASCII("rgb_cloud.pcd", *rgb_cloud);
    std::cout << "✅ 彩色点云已保存 rgb_cloud.pcd" << std::endl;

    // 读取彩色PCD
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr load_rgb(new pcl::PointCloud<pcl::PointXYZRGB>);
    if (pcl::io::loadPCDFile<pcl::PointXYZRGB>("rgb_cloud.pcd", *load_rgb) == -1)
    {
        PCL_ERROR("❌ 加载彩色点云失败\n");
        return -1;
    }

    // 读取颜色与坐标
    for (const auto& p : *load_rgb)
    {
        std::cout << "坐标: " << p.x << "," << p.y << "," << p.z
                  << "  颜色 R:" << (int)p.r << " G:" << (int)p.g << " B:" << (int)p.b << std::endl;
    }

    return 0;
}