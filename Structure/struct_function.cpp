// 结构体 作为 函数参数
// 作用： 将结构体作为参数向函数中传递

// 传递的方式有两种：
        //    值传递  -- 形参改变 实参不变 
        //    地址传递  -- 会改变实参


#include <iostream>

using namespace std;


// 结构体定义 
struct Student
{
    //成员列表
    string name;  //名字
    int age;      //年龄 
    int score;    //分数
};

// 值传递形式
void print_Student_1( struct Student s )
{

    cout << s.name << "  " << s.age << "  " << s.score << endl;

}

// 指针传递形式
void print_Student_2( struct Student *s )
{

    cout << s->name << "  " << s->age << "  " << s->score << endl;

}


int main()
{
    // 创建 结构体变量  
    struct Student Std =  { "ya" , 23 , 100 };

    // 调用 值传递
    print_Student_1(Std);

    // 调用 指针传递  -- Std 是个变量  因此 必须使用 &!
    print_Student_2(&Std);

    cout << Std.name << "  " << Std.age << "  " << Std.score << endl;

    cout <<"Hello,ya!"<< endl;
    system("pause");
    return 0;
}