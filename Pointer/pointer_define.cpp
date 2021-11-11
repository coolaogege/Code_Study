// 指针 -- 通过指针间接访问内存

    // 内存编号是从0开始记录的，一般用十六进制数字表示
    // 可以使用指针变量保存地址

// 指针所占的内存空间 
//          ---- 指针也是一种数据类型 因此也可获取 指针的 内存空间 

#include <iostream>

using namespace std;

int main()
{
    // 定义一个指针  -- 语法 ： 数据类型 * 指针变量名
    int a = 10;


    // int * p;  // 定义一个指针类型
    // p = &a;  // 让 p 取到a地址  & 取址

    // 等价于  int * p = &a ;  ----  定义一个p的指针 指向a的地址！
    int * p = &a ; 


    cout << &a << endl;   // 0x61ff08
    cout << p << endl;    // 0x61ff08

    // 指针前 加 *  代表解引用 ，找到 指针指向的内存  ---  通过 *p  可以访问内存 也可以进行修改 内存！
    cout << *p << endl;  // 输出为 a 的值 10

    // 指针所占的内存空间  
    // -- 32位操作系统中  指针 占4字节空间    
    // -- 64位操作系统中  指针 占8字节空间

    // 会发现全是 4 字节！！
    cout << sizeof(p) << endl;  // 输出  4  即 一个指针  占用 4字节空间大小！  
    cout << sizeof(int *) << endl; // 输出 int型 指针  4字节！
    cout << sizeof(float *) << endl; 
    cout << sizeof(double *) << endl;
    cout << sizeof(char *) << endl;


    system("pause");
    return 0;
}