// 结构体
// 概念 - 结构体 属于 用户自定义的 数据类型  -- 允许存储不同的数据类型

/* 
结构体 定义 与 使用
    语法： struct 结构体名 { 结构体成员列表 }；
    通过结构体创建变量的方式有三种：
         1.struct 结构体名 变量名
         2.struct 结构体名 变量名 = { 成员1值 ， 成员2值 ... }
         3.定义结构体时顺便创建变量 
*/


#include <iostream>

using namespace std;


// 结构体定义 -- 一些类型的集合组成的一个类型
struct Student
{
    //成员列表
    string name;  //名字
    int age;      //年龄 
    int score;    //分数
};


int main()
{
    // C++ 中 创建 结构体变量时   struct 可以省略  定义结构体时 不可省略！ 

    // 第1种创建
    struct Student S1; 
    // 给S1属性赋值  -- 通过 结构体变量.
    S1.name = "ya";
    S1.age = 23 ;
    S1.score = 100 ;

    cout << S1.name << "  " << S1.age << "  " << S1.score << endl;   

    // 第2种创建
    struct Student S2 = { "sm" , 24 , 80 };

    cout << S2.name << "  " << S2.age << "  " << S2.score << endl;  

    // 第3种创建 -- 创建结构体时 直接就创建了 结构体变量！
    struct Teacher
    {
        //成员列表
        string name;  //名字
        int age;      //年龄 
    }S3;

    S3.name = "jm";
    S3.age = 50 ;

    cout << S3.name << "  " << S3.age << endl; 

    cout <<"Hello,ya!"<< endl;
    system("pause");
    return 0;
}