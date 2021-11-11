// 结构体指针
// 作用：通过指针访问结构体中的成员

//      利用操作符 -> 可以通过 结构体指针 访问 结构体属性

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

struct Student2
{
    //成员列表
    string name;  //名字
    int age;      //年龄 
    int score;    //分数
};

int main()
{
    // 创建 结构体变量  
    struct Student Std =  { "ya" , 23 , 100 };

    // 通过指针 指向 结构体变量
    struct Student * p = &Std ;

    // 通过指针 访问 结构体变量的属性
    cout << p->name << "  " << p->age << "  " << p->score << endl;


    // 创建 结构体数组  
    struct Student2 StdArray[3] = 
    {
        { "ya" , 23 , 100 },
        { "sm" , 24 , 80 },
        { "wy" , 17 , 90 }
    };

    // 通过指针 指向 结构体数组
    struct Student2 * p2 = StdArray ;

    // 通过指针 访问 结构体变量的属性 
    cout << (++p2)->name << "  " << (++p2)->age << "  " << (++p2)->score << endl;   //  sm , 24 , 80

    p2 = StdArray ;
    cout << (p2+2)->name << "  " << (p2+2)->age << "  " << (p2+2)->score << endl;   //  wy , 17 , 90


    p2 = StdArray ;
    // StdArray[0]修改值  -- 通过  指针->
    p2->name = "jm";
    p2->age = 50 ;
    p2->score = 200 ;

    //进行遍历！
    for (int i = 0; i < 3; i++)
    {
        cout << (p2+i)->name << "  " << (p2+i)->age << "  " << (p2+i)->score << endl;
    }
    
    
    cout <<"Hello,ya!"<< endl;
    system("pause");
    return 0;
}