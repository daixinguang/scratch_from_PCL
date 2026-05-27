#include <iostream>
#include <vector>

// 模拟点类型
struct PointXYZ {
    float x, y, z;
};

int main()
{
    // 1. 定义容器：对应 PCL 点云集合
    std::vector<PointXYZ> cloud;

    // 2. 尾部添加元素（最常用）
    cloud.push_back({1.0f, 1.0f, 1.0f});
    cloud.push_back({2.0f, 2.0f, 2.0f});
    cloud.push_back({3.0f, 3.0f, 3.0f});

    std::cout << "点云总数量: " << cloud.size() << "\n" << std::endl;

    // 3. 下标遍历（类似 pcl::PointCloud 的 [] 访问）
    std::cout << "===== 下标遍历 =====" << std::endl;
    for (size_t i = 0; i < cloud.size(); ++i)
    {
        std::cout << "idx " << i 
                  << ": " << cloud[i].x << ", " << cloud[i].y << ", " << cloud[i].z << std::endl;
    }

    // 4. 范围 for 遍历（C++11 推荐，PCL 现代代码主流写法）
    std::cout << "\n===== 范围for遍历 =====" << std::endl;
    for (const auto& pt : cloud)  // const引用，避免拷贝
    {
        std::cout << pt.x << ", " << pt.y << ", " << pt.z << std::endl;
    }

    // 5. 删除最后一个元素
    cloud.pop_back();
    std::cout << "\n删除尾部点后，数量: " << cloud.size() << std::endl;

    // 6. 清空容器
    cloud.clear();
    std::cout << "清空后，数量: " << cloud.size() << std::endl;

    return 0;
}