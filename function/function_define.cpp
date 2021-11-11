//函数
//     -将代码封装  减少重复代码
//     -分成若干的程序块，每个模块实现特定的功能

/*
函数定义步骤 -- 5steps
    1.返回值类型
    2.函数名
    3.参数列表
    4.函数体语句
    5.return表达式 
*/

/* 
    返回值类型 函数名 (参数列表)
    {
        函数体语句

        return表达式
    } 
*/


#include <iostream>

using namespace std;

//函数的声明  -- 提前告诉编译器 函数的存在   --- 新版的不需要声明了！！
int max(int a , int b);


/* 
    函数的常见形式
        1.无参无返
        2.有参无返
        3.无参有返
        4.有参有返 
*/

// 无参无返
void test01()
{
    cout << "test01" << endl;
}

//有参无返
void test02(int a)
{
    cout << "test02" << endl;
}

//无参有返
int test03()
{
    return 100;
}

//有参有返
int add(int num1 , int num2)
{
    int sum = num1 + num2;
    
    return sum;
}

//如果不需要返回值 声明的时候写void
void swap(int num1 , int num2)
{
    cout << num1 << "  " << num2 << endl;

    int temp = 0;
    temp = num1;
    num1 = num2;
    num2 = temp;

    cout << num1 << "  " << num2 << endl;

    //return;  //---- 返回值不需要的时候，可以不写return
}

int main()
{
    int a = 3;
    int b = 4;

    cout << add(3,4) << endl; // 输出 7

    swap(a,b);  // 注意 形参  实参的变化！！！

    cout << a << "  " << b << endl; // 输出还是原来的值!

    test02(100);

    int test03_value = test03();
    cout << test03_value << endl; 

    cout << max(a,b) << endl; // 输出两者最大值

    system("pause");

    return 0;
}


int max(int a , int b)
{
    return a>b ? a : b;
}