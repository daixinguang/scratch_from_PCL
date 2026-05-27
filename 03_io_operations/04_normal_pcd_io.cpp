#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <iostream>

int main()
{
    // 带法向量点云类型 PointXYZNormal
    pcl::PointCloud<pcl::PointNormal>::Ptr normal_cloud(new pcl::PointCloud<pcl::PointNormal>);
    normal_cloud->resize(3);

    // 赋值坐标 + 法向量
    normal_cloud->points[0] = {1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 1.0f};
    normal_cloud->points[1] = {4.0f, 5.0f, 6.0f, 0.0f, 1.0f, 0.0f};
    normal_cloud->points[2] = {7.0f, 8.0f, 9.0f, 1.0f, 0.0f, 0.0f};

    // 保存
    pcl::io::savePCDFileASCII("normal_cloud.pcd", *normal_cloud);
    std::cout << "✅ 带法向量点云已保存 normal_cloud.pcd" << std::endl;

    // 读取
    pcl::PointCloud<pcl::PointNormal>::Ptr load_normal(new pcl::PointCloud<pcl::PointNormal>);
    if (pcl::io::loadPCDFile<pcl::PointNormal>("normal_cloud.pcd", *load_normal) == -1)
    {
        PCL_ERROR("❌ 加载法向量点云失败\n");
        return -1;
    }

    // 打印坐标与法向量
    for (const auto& p : *load_normal)
    {
        std::cout << "坐标: " << p.x << "," << p.y << "," << p.z
                  << "  法向量: " << p.normal_x << "," << p.normal_y << "," << p.normal_z << std::endl;
    }

    return 0;
}