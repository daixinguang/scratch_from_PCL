#include <iostream>
#include <string>

// 模拟点云结构体
struct PointXYZ {
    float x, y, z;
};

// 1. 值传递：会拷贝对象，大对象开销高（PCL 禁止这种写法）
void modify_by_value(PointXYZ pt)
{
    pt.x = 10.0f;
    std::cout << "值传递内部修改: x = " << pt.x << std::endl;
}

// 2. 普通引用：直接操作原对象，可修改数据
void modify_by_ref(PointXYZ& pt)
{
    pt.x = 20.0f;
    std::cout << "引用传递内部修改: x = " << pt.x << std::endl;
}

// 3. const 引用：只读，禁止修改（PCL 读取点云数据标准写法）
void read_by_const_ref(const PointXYZ& pt)
{
    std::cout << "const引用读取: x = " << pt.x << std::endl;
    // pt.x = 30;  // 编译报错，const 不可修改
}

int main()
{
    PointXYZ pt{1.0f, 2.0f, 3.0f};
    std::cout << "初始值: x = " << pt.x << "\n" << std::endl;

    modify_by_value(pt);
    std::cout << "值传递后原值: x = " << pt.x << "\n" << std::endl;

    modify_by_ref(pt);
    std::cout << "引用传递后原值: x = " << pt.x << "\n" << std::endl;

    read_by_const_ref(pt);

    return 0;
}