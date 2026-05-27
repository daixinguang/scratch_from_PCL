#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <iostream>

// 全局标记：标记是否触发截图
bool g_take_screenshot = false;

// 键盘回调函数
void keyboardEventOccurred(const pcl::visualization::KeyboardEvent& event, void* nothing)
{
    // 按下 s 键
    if (event.getKeySym() == "s" && event.keyDown())
    {
        g_take_screenshot = true;
        std::cout << "检测到 s 键，准备截图..." << std::endl;
    }
}

int main()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    for (int i = 0; i < 400; ++i)
    {
        pcl::PointXYZ pt;
        pt.x = rand() % 10;
        pt.y = rand() % 10;
        pt.z = rand() % 10;
        cloud->push_back(pt);
    }

    pcl::visualization::PCLVisualizer viewer("View & Screenshot");
    // 注册键盘回调
    viewer.registerKeyboardCallback(keyboardEventOccurred, nullptr);

    viewer.addCoordinateSystem(2.0);
    viewer.setBackgroundColor(10, 10, 10);
    viewer.addPointCloud(cloud, "cloud");
    viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "cloud");

    // 预设相机视角
    viewer.setCameraPosition(5, 5, 15, 0, 0, 0);

    std::cout << "按 s 键截图，按 q 退出窗口\n";

    while (!viewer.wasStopped())
    {
        viewer.spinOnce(10);

        // 执行截图
        if (g_take_screenshot)
        {
            viewer.saveScreenshot("./data/view_screenshot.png");
            std::cout << "✅ 截图已保存为 view_screenshot.png\n";
            g_take_screenshot = false; // 重置标记
        }
    }

    return 0;
}