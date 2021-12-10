
/* #### 4.2.2 构造函数的分类及调用

两种分类方式：

​	按参数分为： 有参构造和无参构造

​	按类型分为： 普通构造和拷贝构造

三种调用方式：

​	括号法

​	显示法

​	隐式转换法 */



#include <iostream>

using namespace std;

class Person {
public:
	//无参（默认）构造函数
	Person() {
		cout << "No-argument constructor" << endl;
	}
	//有参构造函数
	Person(int a) {
		age = a;
		cout << "Parameterized constructor" << endl;
	}
	//拷贝构造函数 -- 把zhangsan的所有属性 给拷贝到我身上  使用 引用 的方式
	Person(const Person& p) {
		age = p.age;
		cout << "Copy constructor" << endl;
	}
	//析构函数
	~Person() {
		cout << "Destructor" << endl;
	}
public:
	int age;
};



//2、构造函数的调用
//调用无参构造函数
void test01() {
	Person p; //调用无参构造函数
}

//调用有参的构造函数
void test02() {

	//2.1  括号法，常用
	Person p1(10);
	//注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
	//Person p2();

	//2.2 显式法
	Person p2 = Person(10); 
	Person p3 = Person(p2);
    //cout << p3.age << endl;
	//Person(10)单独写就是匿名对象  当前行结束之后，马上析构

	//2.3 隐式转换法
	Person p4 = 10; // Person p4 = Person(10); 
	Person p5 = p4; // Person p5 = Person(p4); 

	//注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明  --- Person p4 = Person p4;  与上面的声明重复了
	//Person p5(p4);
}

int main() {

	//test01();
	test02();
    

	system("pause");

	return 0;
}