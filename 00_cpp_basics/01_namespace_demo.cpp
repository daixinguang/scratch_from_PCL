#include <iostream>

// 模拟 PCL 风格：自定义命名空间
namespace pcl_demo {
    void print_info(const char* str)
    {
        std::cout << "[pcl_demo] " << str << std::endl;
    }

    // 嵌套命名空间（PCL 内部大量嵌套）
    namespace io {
        void load_file()
        {
            std::cout << "[pcl_demo::io] 模拟加载点云文件" << std::endl;
        }
    }
}

// 全局同名函数，用于对比冲突
void print_info(const char* str)
{
    std::cout << "[global] " << str << std::endl;
}

int main()
{
    // 1. 全局函数调用
    print_info("全局函数");

    // 2. 显式指定命名空间（PCL 最常用写法）
    // PCL 标准写法：始终写 pcl::xxx 显式指定命名空间，PCL、OpenCV 等库都有大量同名接口，极易引发命名冲突。
    pcl_demo::print_info("命名空间内函数");
    pcl_demo::io::load_file();

    /**
     * 3. 引入整个命名空间后，就不需要显式指定命名空间
     * 小型Demo且没有重名函数的情况下可用，当前引入整个命名空间后，print_info有全局同名函数和命名空间内函数因此会报错
     * 大型工程很容易触发此命名冲突，不推荐使用。
     */
    // using namespace pcl_demo;
    // print_info("using namespace 引入后调用");

    // 4. 命名空间别名（简化长命名空间）
    namespace pd = pcl_demo;
    pd::io::load_file();

    return 0;
}