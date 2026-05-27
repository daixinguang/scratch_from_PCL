#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <iostream>

// 演示不同点类型
int main() {
    // 1. 最基本的XYZ点
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_xyz(new pcl::PointCloud<pcl::PointXYZ>);
    
    // 2. 带法向量的点
    pcl::PointCloud<pcl::PointNormal>::Ptr cloud_normal(new pcl::PointCloud<pcl::PointNormal>);
    
    // 3. 带RGB颜色的点（学习结构体）
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_rgb(new pcl::PointCloud<pcl::PointXYZRGB>);
    
    // 添加彩色点
    pcl::PointXYZRGB color_point;
    color_point.x = 1.0;
    color_point.y = 2.0;
    color_point.z = 3.0;
    /**
     * (R << 16) | (G << 8) | B
     * 这是一种可读性比较高的写法，直接将R、G、B三个分量分别左移到对应的位置，然后使用按位或运算符将它们组合成一个整数。
     */
    uint32_t rgb = (255 << 16) | (0 << 8) | 0;  // 红色
    /**
     * reinterpret_cast<float*>(&rgb) 是一种类型转换，将 rgb 的地址 reinterpret_cast 成一个指向 float 的指针。由于 PointXYZRGB 中的 rgb 字段是一个 float 类型，但我们需要将 RGB 颜色信息存储在其中，所以我们通过这种方式将整数形式的 RGB 颜色转换为 float 类型。
     * 为什么要使用 reinterpret_cast 而不是 static_cast？
     * static_cast 主要用于相关类型之间的转换，如基本数据类型之间的转换，或者类层次结构中的指针和引用转换。
     * 而 reinterpret_cast 则用于完全不相关类型之间的转换，或者需要进行底层位操作的情况。
     * 在这里，我们需要将一个整数（RGB 颜色）直接转换为一个浮点数（PointXYZRGB 中的 rgb 字段），这两者在类型上没有任何关系，因此必须使用 reinterpret_cast 来进行这种不安全的转换。
     * 需要注意的是，这种转换可能会导致未定义行为，因此在使用时需要非常小心，确保转换的结果符合预期。
     *
     * 为什么 PointXYZRGB 中的 rgb 字段是 float 类型，而不是 uint32_t？
     * 不是技术上不能用 uint32，而是早期为了 SIMD 对齐 + 文件格式统一，强行把 32 位整数的位模式塞进了 float 里；现在只是历史包袱。
     * 官方推荐：新代码一律用 PointXYZRGBA，不要用 PointXYZRGB 的 float rgb 字段。
     *
     */
    color_point.rgb = *reinterpret_cast<float*>(&rgb);
    cloud_rgb->push_back(color_point);
    
    std::cout << "点云大小: " << cloud_rgb->size() << std::endl;
    std::cout << "RGB值: r=" << (int)color_point.r << " g=" << (int)color_point.g << " b=" << (int)color_point.b << std::endl;
    
    return 0;
}