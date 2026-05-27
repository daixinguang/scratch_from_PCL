#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>

int main(int argc, char** argv) {
    // 创建一个包含5个点的点云
    // Cpp的::语法，指明「隶属于哪个命名空间 / 类 / 作用域」
    // pcl::PointCloud 是指 pcl命名空间，PointCloud点云类，PointXYZ：pcl 空间里的三维点结构体
    // Ptr 是智能指针，自动管理内存，避免手动释放
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    /**
     * 怎么区分::后面的是类还是结构体?
     * 只有参数的是结构体，能创建对象、调用函数的是类。
      pcl::PointCloud<pcl::PointXYZ>::Ptr cloud; // 这是一个智能指针，指向一个 pcl::PointCloud<pcl::PointXYZ> 对象
      pcl::PointCloud<pcl::PointXYZ> cloud; // 这是一个普通对象
     * 结构体和类的区别在于默认访问权限，结构体默认是 public，而类默认是 private。
     * 但在 C++ 中，结构体和类的功能几乎完全相同，都可以有成员函数、构造函数、析构函数等。区别主要在于语义上的约定：结构体通常用于表示数据结构，而类则用于表示具有行为的对象。
     * 在 PCL 中，PointXYZ 是一个结构体，表示一个三维点，包含 x、y、z 三个浮点成员。而 PointCloud 是一个类，表示一个点云，包含一个点的集合以及相关的属性和方法。
     * 这里的 cloud 是一个智能指针，指向一个 PointCloud 对象。我们通过 new 关键字创建了一个 PointCloud 对象，并将其地址赋值给 cloud 智能指针。智能指针会自动管理内存，当 cloud 不再使用时，它会自动释放内存，避免内存泄漏。
     */
    cloud->width = 5;
    cloud->height = 1;
    // is_dense 表示点云中是否有无效点（如NaN或Inf）。设置为false表示点云可能包含无效点,
    // 这在某些处理算法中很重要，因为它们可以根据这个标志位先剔除无效点再计算。
    cloud->is_dense = false;
    // points 是一个存储点云数据的向量，resize调整其大小以容纳指定数量的点。
    cloud->points.resize(cloud->width * cloud->height);
    
    // 填充点云数据
    // size_t 是平台自适应无符号整数类型。
    // 32 位系统 = unsigned int
    // 64 位系统 = unsigned long long
    for (size_t i = 0; i < cloud->points.size(); ++i) {
        // static_cast<目标类型>(原数据) 是 C++ 中的类型转换操作符，用于将一个值转换为指定的类型。
        // 这种C++标准强转替代了C语言的老式强转 `(float)i`。
        cloud->points[i].x = static_cast<float>(i);
        cloud->points[i].y = static_cast<float>(i * i);
        cloud->points[i].z = 0.0f;
    }
    
    std::cout << "Generated point cloud with " << cloud->size() << " points:" << std::endl;
    // const auto& point : cloud->points 是 C++11 引入的范围-based for 循环语法，简化了对容器元素的迭代。
    /**
     * auto 是 C++11 引入的类型推断关键字，编译器会根据初始化表达式自动推断变量的类型。
     * const auto& point 是一个常量引用，指向 cloud->points 中的每个点。使用引用避免了不必要的复制，提高了性能。
     * cloud->points 是一个 std::vector，存储了点云中的所有点。通过范围-based for 循环，我们可以直接访问每个点，而不需要使用索引。
     * 这种语法使代码更简洁、更易读，同时也减少了出错的可能性（如越界访问）。在循环体内，我们打印了每个点的坐标信息。
     */
    /**
     * 为什么这里的for循环要用const auto& point而不是auto point呢？
     * 因为auto point会创建一个新的point对象，导致每次循环都进行一次复制操作，而const auto& point则是一个常量引用，直接引用原来的point对象，避免了不必要的复制，提高了性能。
     * */
    /**
     * 这里的&是什么意思？
     * 在C++中，&符号有两种主要用途：取地址和引用。在这个上下文中，&是引用符号，表示point是一个引用类型。
     * 引用是一种别名机制，它允许我们创建一个变量的别名，而不是创建一个新的变量。
     * 当我们使用const auto& point时，point是cloud->points中的每个元素的引用，这意味着我们直接访问原始数据，而不是创建一个副本。
     */
    for (const auto& point : cloud->points) {
        std::cout << "  (" << point.x << ", " << point.y << ", " << point.z << ")" << std::endl;
    }
    
    // 保存到文件
    pcl::io::savePCDFileASCII("test_pcd.pcd", *cloud);
    std::cout << "Saved test_pcd.pcd" << std::endl;
    
    // 可视化（如果可用）
    // 创建一个PCLVisualizer对象，命名为"3D Viewer"
    pcl::visualization::PCLVisualizer::Ptr viewer(new pcl::visualization::PCLVisualizer("3D Viewer"));
    // 设置背景颜色为黑色
    viewer->setBackgroundColor(0, 0, 0);
    // 将点云添加到可视化器中，命名为"sample cloud"
    viewer->addPointCloud<pcl::PointXYZ>(cloud, "sample cloud");
    // 设置点云的渲染属性，这里设置点的大小为5
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, "sample cloud");
    // 添加坐标系，参数1.0表示坐标轴的长度
    viewer->addCoordinateSystem(1.0);
    // 初始化相机参数
    viewer->initCameraParameters();
    // 进入可视化循环，直到用户关闭窗口
    while (!viewer->wasStopped()) {
        viewer->spinOnce(100);
    }

    return 0;
}