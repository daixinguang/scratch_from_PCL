#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <iostream>

int main()
{
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr rgb_cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    rgb_cloud->resize(300);

    // 填充坐标+颜色
    for (auto& pt : *rgb_cloud)
    {
        pt.x = rand() % 8; // 生成0-7之间的随机整数
        pt.y = rand() % 8;
        pt.z = rand() % 8;
        pt.r = 255;
        pt.g = 100;
        pt.b = 100;
    }

    pcl::visualization::PCLVisualizer viewer("RGB Cloud Viewer");
    viewer.addCoordinateSystem(1.5); // 显示坐标轴，长度1.5
    viewer.setBackgroundColor(20, 20, 20); // 背景暗灰色

    // 添加彩色点云
    viewer.addPointCloud(rgb_cloud, "rgb_cloud");
    // 设置点云渲染属性：点大小为3,颜色由点云本身的RGB值决定(PointXYZRGB)
    viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "rgb_cloud");

    while (!viewer.wasStopped())
    {
        viewer.spinOnce(10);
    }

    return 0;
}