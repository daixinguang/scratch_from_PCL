#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

int main()
{
    pcl::PointCloud<pcl::PointXYZ> cloud1;
    cloud1.push_back({1,2,3});

    // 深拷贝
    pcl::PointCloud<pcl::PointXYZ> cloud2 = cloud1;

    // 修改 cloud2 不会影响 cloud1
    cloud2[0].x = 100;

    printf("cloud1: %.1f\n", cloud1[0].x);
    printf("cloud2: %.1f\n", cloud2[0].x);
    return 0;
}