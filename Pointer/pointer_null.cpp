// 空指针  

// 空指针 -- 指针变量 指向内存中编号为0的空间
//        -- 初始化指针变量
//         -- 空指针指向的内存是不可访问的

#include <iostream>

using namespace std;

int main()
{
    // 初始化指针变量

    int * p = NULL ;  

    //空指针指向的内存是不可访问的   0-255 之间的编号 是 系统占用的的 因此不能访问！
    *p = 100 ;

    cout <<"Hello,ya!"<< endl;

    system("pause");
    return 0;
}