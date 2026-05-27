#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

int main()
{
    pcl::PointCloud<pcl::PointXYZ> cloud;
    cloud.push_back({0,0,0});

    // 修改点
    auto& pt = cloud[0];
    pt.x = 10;
    pt.y = 20;
    pt.z = 30;

    printf("修改后：%.1f %.1f %.1f\n", pt.x, pt.y, pt.z);
    return 0;
}