#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

int main()
{
    // 创建智能指针点云
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

    // 添加点
    cloud->push_back({1,2,3});
    cloud->push_back({4,5,6});

    printf("点云数量：%ld\n", cloud->size());
    printf("第一个点：%.1f %.1f %.1f\n", cloud->at(0).x, cloud->at(0).y, cloud->at(0).z);

    return 0;
}