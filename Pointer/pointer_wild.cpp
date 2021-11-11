// 野指针  

// 野指针 -- 指针变量 指向非法的内存空间
//        -- 初始化指针变量
//         -- 空指针指向的内存是不可访问的

#include <iostream>

using namespace std;

int main()
{
    // 指针变量p 指向内存地址编号为0x1100的空间

    int * p = (int *)0x1100 ;    // 0x1100  ---- 一个数  使用 (int *) 强转成 一个指针！

    //程序中避免出现野指针！！
    cout << *p << endl;

    cout <<"Hello,ya!"<< endl;

    system("pause");
    return 0;
}