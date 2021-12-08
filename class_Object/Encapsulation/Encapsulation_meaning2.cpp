/* **封装意义二：**

类在设计时，可以把属性和行为放在不同的权限下，加以控制 */


/* 访问权限有三种：
1. public        公共权限     成员类内可以访问  类外可以访问
2. protected 保护权限         成员类内可以访问  类外不可以访问   继承中  儿子可以访问父亲中的保护内容
3. private      私有权限      成员类内可以访问  类外不可以访问   继承中  儿子不可以访问父亲中的私有内容
 */  

#include <iostream>

using namespace std;

// class 代表设计的一个类，类后面紧跟着的就是类名称
class Person
{
// 访问权限    

// 公共权限
public:
    string Name; // 姓名

// 保护权限
protected:
    string Car; // 汽车

// 私有权限
private:
    int Password; // 银行卡密码

public:
    void func(){
        Name = "zhangsan";
        Car = "Tesla";
        Password = 123456;
    }

};


int main(){
    // 实例化一个对象 （通过一个类 创建一个对象的过程）
    Person p1;

    p1.Name = "lisi";
    p1.func();

    system("pause");
    return 0;
}