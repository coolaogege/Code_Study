// 结构体数组
// 作用：将 自定义的结构体 放入到数组中 方便维护

// 语法：struct 结构体名 数组名[元素个数] = { {} ,{} ,{}... };



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
    // 创建 结构体数组  
    struct Student StdArray[3] = 
    {
        { "ya" , 23 , 100 },
        { "sm" , 24 , 80 },
        { "wy" , 17 , 90 }
    };

    // 给StdArray[0]修改值  -- 通过 结构体变量.
    StdArray[0].name = "jm";
    StdArray[0].age = 50 ;
    StdArray[0].score = 200 ;

    // 进行遍历！
    for (int i = 0; i < 3; i++)
    {
        cout << StdArray[i].name << "  " << StdArray[i].age << "  " << StdArray[i].score << endl;
    }
    
    
    cout <<"Hello,ya!"<< endl;
    system("pause");
    return 0;
}
