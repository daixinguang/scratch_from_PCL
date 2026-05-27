#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

int main()
{
    // 定义点云类型
    pcl::PointCloud<pcl::PointXYZ> cloud;

    // 设置宽高（无序点云：width=总点数，height=1）
    cloud.width = 5;
    cloud.height = 1;
    cloud.resize(cloud.width * cloud.height);

    // 赋值
    for (auto& pt : cloud) {
        pt.x = 1.0;
        pt.y = 2.0;
        pt.z = 3.0;
    }

    printf("创建成功，共 %ld 个点\n", cloud.size());
    return 0;
}