#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <iostream>

int main()
{
    // 1. 构造测试点云
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    for (int i = 0; i < 500; ++i)
    {
        pcl::PointXYZ pt;
        pt.x = rand() % 10;
        pt.y = rand() % 10;
        pt.z = rand() % 10;
        cloud->push_back(pt);
    }

    // 2. 创建可视化窗口
    pcl::visualization::PCLVisualizer viewer("Simple Cloud Viewer");
    viewer.addCoordinateSystem(2.0);  // 显示坐标轴，长度2.0
    viewer.setBackgroundColor(0, 0, 0); // 背景黑色

    // 3. 添加点云
    viewer.addPointCloud(cloud, "cloud");
    // 设置点云渲染属性：点大小为2,颜色为默认（白色）(PointXYZ 没有颜色属性，所以只能设置全局颜色)
    viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "cloud");

    std::cout << "=== 操作说明 ===\n";
    std::cout << "鼠标左键拖拽：旋转视角\n"; // MAC 用户 单指按下旋转或者三指拖动旋转
    std::cout << "鼠标滚轮：缩放\n"; // MAC 用户双指滚动缩放
    std::cout << "鼠标右键拖拽：平移\n"; // MAC 用户 Shift 键 单指按下或者三指拖动平移
    std::cout << "按 q 退出窗口\n";

    // 4. 循环渲染，直到按q关闭
    while (!viewer.wasStopped())
    {
        viewer.spinOnce(10);
    }

    return 0;
}