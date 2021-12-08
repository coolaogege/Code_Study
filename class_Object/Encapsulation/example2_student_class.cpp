
// **示例2：**设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号

#include <iostream>

using namespace std;

// class 代表设计的一个类，类后面紧跟着的就是类名称
// class 中 属性 成员  都叫他 成员  
// 属性  成员属性  成员变量
// 行为  成员函数  成员方法

class Student
{
// 访问权限    
private:
    /* data */

// 公共权限
public:
    // 属性  -- 变量
    // 姓名 学号
    string Name;
    int ID;

    // 行为  -- 函数
    // 显示姓名和学号
    void showStudent(){
        cout << "name:" << Name << " ID:" << ID << endl;
    }

    // 给属性进行赋值
    void setName(string name){
        Name = name;
    }

};


int main(){
    // 通过学生类  创建一个具体的学生（对象）
    // 实例化一个对象 （通过一个类 创建一个对象的过程）
    Student s1;
    // 给学生对象属性进行赋值
    s1.Name = "zhangsan";
    s1.ID = 1;
    s1.showStudent();
    
    s1.setName("lisi");
    s1.showStudent();

    system("pause");
    return 0;
}