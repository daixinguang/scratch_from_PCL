#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <iostream>

int main()
{
    pcl::PointCloud<pcl::PointXYZ> cloud;
    cloud.push_back({1,2,3});
    cloud.push_back({4,5,6});
    cloud.push_back({7,8,9});

    // 遍历方式1：for each
    std::cout << "== 遍历方式1: for each ==\n";
    for (const auto& pt : cloud) {
        std::cout << pt.x << " " << pt.y << " " << pt.z << "\n";
    }

    // 遍历方式2：下标
    std::cout << "== 遍历方式2>: 下标遍历 ==\n";
    for (size_t i = 0; i < cloud.size(); i++) {
        const auto& pt = cloud[i];
        std::cout << pt.x << " " << pt.y << " " << pt.z << "\n";
    }

    return 0;
}