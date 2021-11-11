// 结构体 中 使用 const使用场景

// 作用： 用 const 防止 误操作！


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


// 指针传递形式  -- 可以在传递时 减少内存空间 而且不会复制出来一个新的副本！
// 加入 const 之后  一旦修改 就会出错 -- 只能用来读属性！
void print_Student_2( const Student *s )
{
    //s->age = 40;  // in read-only object  -- error!
    cout << s->name << "  " << s->age << "  " << s->score << endl;

}


int main()
{
    // 创建 结构体变量  
    struct Student Std =  { "ya" , 23 , 100 };


    // 调用 指针传递  -- Std 是个变量  因此 必须使用 &!
    print_Student_2(&Std);

    cout << Std.name << "  " << Std.age << "  " << Std.score << endl;

    cout <<"Hello,ya!"<< endl;
    system("pause");
    return 0;
}