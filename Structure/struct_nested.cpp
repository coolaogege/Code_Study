// 结构体的嵌套

// 结构体中的成员可以是另一个结构体


#include <iostream>

using namespace std;

// 学生结构体定义 
struct Student
{
    //成员列表
    string name;  //名字
    int age;      //年龄 
    int score;    //分数
};

// 教师结构体定义 
struct Teacher
{
    //成员列表
    int id; //职工编号
    string name;  //名字
    int age;      //年龄 
    struct Student stu;    //子结构体   学生 -- 必须定义此结构体！
};


int main()
{
    Teacher t1; //定义一个 老师结构体 的变量！

    t1.id = 22;
    t1.name = "jiming";
    t1.age = 50;

    t1.stu.name = "ya";
    t1.stu.age = 23;
    t1.stu.score = 100;

    cout << t1.stu.name << endl;

    cout <<"Hello,ya!"<< endl;
    system("pause");
    return 0;
}