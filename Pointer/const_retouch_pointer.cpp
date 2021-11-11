// const 修饰指针

/* 
    有三种情况！
        1. const 修饰指针 -- 常量指针
        2. const 修饰常量 -- 指针变量
        3. const 既修饰指针，又修饰变量 
*/

// const - 常量   
// 记忆： const 、 int *  两个的位置！ 其中 int 可替换为别的数据类型！
// 甄别： const ( int * p ) -- 意味着 *p 被 const --- *p 不可修改  即 *p = 20; 是错误的！！
//        int * const ( p ) -- 意味着 p  被 const ---  p 不可修改   即 p = &b; 是错误的！！



//测试  const 修饰指针 -- 常量指针
/* 
#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = 30;

    // 常量指针 -- 指针指向 可以更改   但是  指针指向的值 不可以修改 
    const int * p = &a; // 定义一个指针  指向 a的 地址！

    cout << *p << endl;

    //*p = 20 ; // 即 想要修改 指针指向的值  ---- 会出现错误！

    p = &b;   // 即 想要修改 指针的指向    ---- 可以运行！  --  解指针 *p 变为30 

    cout << *p << endl;

    cout <<"Hello,ya!"<< endl;

    system("pause");
    return 0;
} 
*/


//测试  const 修饰常量 -- 指针变量
/* 
#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = 30;

    // 指针常量 -- 指针指向 不可以更改   但是  指针指向的值 可以修改 
    int * const p = &a; // 定义一个指针  指向 a的 地址！

    cout << *p << endl;

    *p = 20 ;   // 即 想要修改 指针指向的值  ---- 可以运行！  --  解指针 *p 变为20

    //p = &b;   // 即 想要修改 指针的指向    ---- 会出现错误！  

    cout << *p << endl;

    cout <<"Hello,ya!"<< endl;

    system("pause");
    return 0;
}  
*/

//测试  const 既修饰指针，又修饰变量
#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = 30;

    // 指针指向 不可以更改   同时  指针指向的值 不可以修改 
    const int * const p = &a; // 定义一个指针  指向 a的 地址！

    cout << *p << endl;

    //*p = 20 ;   // 即 想要修改 指针指向的值  ---- 会出现错误！  

    //p = &b;     // 即 想要修改 指针的指向    ---- 会出现错误！  

    cout <<"Hello,ya!"<< endl;

    system("pause");
    return 0;
} 