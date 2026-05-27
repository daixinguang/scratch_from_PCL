#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <iostream>

int main()
{
    // 构造两组点云
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2(new pcl::PointCloud<pcl::PointXYZ>);

    for (int i = 0; i < 200; ++i)
    {
        pcl::PointXYZ p1, p2;
        p1.x = rand() % 5;
        p1.y = rand() % 5;
        p1.z = rand() % 5;

        p2.x = rand() % 5 + 5;
        p2.y = rand() % 5;
        p2.z = rand() % 5;

        cloud1->push_back(p1);
        cloud2->push_back(p2);
    }

    pcl::visualization::PCLVisualizer viewer("Multi Cloud Viewer");
    viewer.addCoordinateSystem(2.0);
    viewer.setBackgroundColor(0, 0, 0);

    // 第一组：红色
    viewer.addPointCloud(cloud1, "cloud1");
    viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "cloud1");
    // 全局颜色设置
    viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 1, 0, 0, "cloud1");

    // 第二组：蓝色
    viewer.addPointCloud(cloud2, "cloud2");
    viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "cloud2");
    viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 0, 0, 1, "cloud2");

    while (!viewer.wasStopped())
    {
        viewer.spinOnce(10);
    }

    return 0;
}