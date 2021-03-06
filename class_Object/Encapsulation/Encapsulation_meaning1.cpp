/* C++面向对象的三大特性为：==封装、继承、多态==

C++认为==万事万物都皆为对象==，对象上有其属性和行为

**例如：**

​	人可以作为对象，属性有姓名、年龄、身高、体重...，行为有走、跑、跳、吃饭、唱歌...

​	车也可以作为对象，属性有轮胎、方向盘、车灯...,行为有载人、放音乐、放空调...

​	具有相同性质的==对象==，我们可以抽象称为==类==，人属于人类，车属于车类 */



/* ### 4.1 封装

#### 4.1.1  封装的意义

封装是C++面向对象三大特性之一

封装的意义：

* 将属性和行为作为一个整体，表现生活中的事物
* 将属性和行为加以权限控制 */


// **封装意义一：**

// ​	在设计类的时候，属性和行为写在一起，表现事物

// **语法：** `class 类名{   访问权限： 属性  / 行为  };`


#include <iostream>

using namespace std;

// **示例1：**设计一个圆类，求圆的周长

// 圆的周长公式 2*PI*r

//圆周率
const double PI = 3.14;

// class 代表设计的一个类，类后面紧跟着的就是类名称
class Cricle
{
// 访问权限    
private:
    /* data */

// 公共权限
public:
    // 属性  -- 变量
    // 半径
    int r;

    // 行为  -- 函数
    // 获取圆的周长
    double calculateZC(){
        return 2*PI*r;
    }

};


int main(){
    // 通过圆类  创建一个具体的圆（对象）
    // 实例化一个对象 （通过一个类 创建一个对象的过程）
    Cricle c1;
    // 给圆对象属性进行赋值
    c1.r = 10;
    cout << "The circumference of the circle is:  " << c1.calculateZC() << endl;

    system("pause");
    return 0;
}
