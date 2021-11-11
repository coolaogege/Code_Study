// 结构体案例


#include <iostream>
#include <ctime>

using namespace std;


// 学生结构体定义 
struct Student
{
    //成员列表
    string name;  //名字
    int score;    //分数
};

// 教师结构体定义 
struct Teacher
{
    //成员列表
    string name;  //名字
    struct Student stu[5];    //子结构体   学生 -- 必须定义此结构体！
};

// 给 老师和学生 赋值的 函数
void allocatSpace(struct Teacher t[] , int len)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < len; i++)
    {
        t[i].name = "Teacher_";
        t[i].name += nameSeed[i];

        for (int j = 0; j < 5; j++)
        {
            t[i].stu[j].name = "Stu_";
            t[i].stu[j].name += nameSeed[j];
            int random = rand()%61 + 40;     // 0-60 ---> 40-100
            t[i].stu[j].score = random;
        }
        
    }
}

// 打印 老师和学生 值的 函数   
void printInfo(struct Teacher t[] , int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << t[i].name << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << t[i].stu[j].name << "  " << t[i].stu[j].score << endl;
        }
        
    }
}

int main()
{
    // 随机数种子
    srand( (unsigned int)time(NULL) );  // 别忘记头文件！

    Teacher tea[3]; //定义一个 老师结构体 的数组！

    // 调用函数  - 赋值
    int len = sizeof(tea)/sizeof(tea[0]);
    allocatSpace(tea , len);

    printInfo(tea , len);

    cout <<"Hello,ya!"<< endl;
    system("pause");
    return 0;
}