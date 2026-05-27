#include <iostream>
#include <memory>   // 智能指针头文件

// 模拟点云类
class PointCloud {
public:
    PointCloud()  { std::cout << "点云对象 构造" << std::endl; }
    ~PointCloud() { std::cout << "点云对象 析构（内存自动释放）" << std::endl; }

    void print()
    {
        std::cout << "执行点云操作" << std::endl;
    }
};

// 函数接收智能指针（PCL 接口常见形式）
void use_cloud(std::shared_ptr<PointCloud> cloud_ptr)
{
    /**
     * 函数传参的智能指针在函数内部会增加引用计数，确保在函数执行期间对象不会被销毁。
     * 当函数结束时，传入的智能指针会自动减少引用计数，如果没有其他智能指针引用同一个对象，内存会被自动释放。
     */
    std::cout << "函数内引用计数: " << cloud_ptr.use_count() << std::endl;
    cloud_ptr->print();
}

int main()
{
    // 1. 创建 shared_ptr 管理对象（推荐写法）
    std::shared_ptr<PointCloud> cloud1 = std::make_shared<PointCloud>();
    std::cout << "初始引用计数: " << cloud1.use_count() << "\n" << std::endl;

    // 2. 拷贝智能指针：引用计数 +1（多个指针共享同一个对象）
    std::shared_ptr<PointCloud> cloud2 = cloud1;
    std::cout << "拷贝后引用计数: " << cloud1.use_count() << "\n" << std::endl;

    // 3. 函数传参，计数继续增加
    use_cloud(cloud1);
    std::cout << "函数执行完后引用计数: " << cloud1.use_count() << "\n" << std::endl;
    /**
     * 4. 置空指针，引用计数 -1
     * 置空指针后，原来指向对象的智能指针 cloud2 不再拥有该对象的所有权，引用计数会减少 1。
     * 当 cloud2 被置空后，cloud1 的引用计数会变为 1，表示只有 cloud1 还在拥有该对象的所有权。
     */
    cloud2.reset();
    std::cout << "\ncloud2 置空后，引用计数: " << cloud1.use_count() << std::endl;

    // 作用域结束，所有智能指针自动销毁，对象内存自动释放
    return 0;
}