#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <iostream>

int main()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

    // 路径：项目根目录 data 文件夹下的 test.pcd
    std::string pcd_path = "../../data/test.pcd";

    // 加载外部PCD文件
    if (pcl::io::loadPCDFile<pcl::PointXYZ>(pcd_path, *cloud) == -1)
    {
        PCL_ERROR("❌ 未找到文件或加载失败: %s\n", pcd_path.c_str());
        return -1;
    }

    std::cout << "✅ 外部点云加载完成" << std::endl;
    std::cout << "点数: " << cloud->size() 
              << " | 宽度: " << cloud->width 
              << " | 高度: " << cloud->height << std::endl;

    // 打印前5个点坐标
    size_t print_num = cloud->size() > 5 ? 5 : cloud->size();
    for (size_t i = 0; i < print_num; ++i)
    {
        std::cout << "点" << i << ": " 
                  << cloud->points[i].x << " "
                  << cloud->points[i].y << " "
                  << cloud->points[i].z << std::endl;
    }

    return 0;
}