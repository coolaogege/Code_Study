/* #### 4.5.2 左移运算符重载


作用：可以输出自定义数据类型 */


// Person p   p.m_a = 10;    p.m_b = 10; 
// cout << p << endl ;    这样是输出不了的 ，因此要重载 <<  


// > 总结：重载左移运算符配合友元可以实现输出自定义数据类型

#include <iostream>

using namespace std;


class Person {
    // 友元 --->  访问 私有的属性
	friend ostream& operator<<(ostream& cout, Person& p);

public:

	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

	//成员函数 实现不了  p << cout 不是我们想要的效果
	//void operator<<(Person& p){
	//}

    //void operator<<( cout )  ---->   类比 operator+(Person& p)  P + p  
    // ---->  P << cout  这样是不对的！ 不会利用成员函数 重载 左移运算符

private:
	int m_A;
	int m_B;
};

//全局函数实现左移重载
//ostream对象只能有一个
// 类比 ： operator<<( cout, p)  --->  cout << p 
// cout 数据类型为  ostream  标准输出流  全局只有一个  用 引用的方式！
ostream& operator<<(ostream& cout, Person& p) {
	cout << "a:" << p.m_A << " b:" << p.m_B;
	return cout;
}

void test() {

	Person p1(10, 20);

	cout << p1 << endl; //链式编程
}

int main() {

	test();

	system("pause");

	return 0;
}