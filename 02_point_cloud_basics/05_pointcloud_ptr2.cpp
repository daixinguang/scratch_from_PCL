#include <iostream>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

// 演示三种指针用法
void raw_pointer_demo() {
    // 原始指针（需要手动delete）
    pcl::PointCloud<pcl::PointXYZ>* cloud = new pcl::PointCloud<pcl::PointXYZ>();
    cloud->push_back(pcl::PointXYZ(1,2,3));
    delete cloud;  // 容易忘记！
}

void shared_ptr_demo() {
    // PCL最常用的方式：共享指针,实际上就是std::shared_ptr的别名，自动管理内存，推荐使用
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    cloud->push_back(pcl::PointXYZ(1,2,3));
    // 自动释放，不需要delete
}

void reference_demo() {
    // 引用传递（避免拷贝）
    pcl::PointCloud<pcl::PointXYZ> cloud;
    cloud.push_back(pcl::PointXYZ(1,2,3));
    /**
     * Lambda表达式：一种匿名函数，可以直接在需要函数对象的地方定义和使用。
     * 语法为 [捕获列表] (参数列表) -> 返回类型 {函数体}。
     */
    auto process = [](pcl::PointCloud<pcl::PointXYZ>& c) {
        for (auto& p : c) p.x += 1;
    };
    process(cloud);
}

int main() {
    std::cout << "=== 指针演示 ===" << std::endl;
    std::cout << "1. 原始指针: 容易内存泄漏" << std::endl;
    std::cout << "2. PCL::Ptr: 自动管理，推荐使用" << std::endl;
    std::cout << "3. 引用: 函数参数传递" << std::endl;
    
    shared_ptr_demo();  // PCL标准写法
    return 0;
}