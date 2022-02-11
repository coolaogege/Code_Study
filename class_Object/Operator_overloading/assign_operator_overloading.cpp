
/* #### 4.5.4 赋值运算符重载

c++编译器至少给一个类添加4个函数

1. 默认构造函数(无参，函数体为空)
2. 默认析构函数(无参，函数体为空)
3. 默认拷贝构造函数，对属性进行值拷贝
4. 赋值运算符 operator=, 对属性进行值拷贝



如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题 */

#include <iostream>

using namespace std;

class Person
{
public:

	Person(int age)
	{
		//将年龄数据开辟到堆区---new
		m_Age = new int(age);
	}

	//重载赋值运算符 
	Person& operator=(Person &p)
	{
        // 先判断是否有堆区内存 如果有 先释放干净！
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		//编译器提供的代码是浅拷贝
		//m_Age = p.m_Age;

		//提供深拷贝 解决浅拷贝的问题
		m_Age = new int(*p.m_Age);

		//返回自身
		return *this;
	}

    // 析构函数  对  堆区的数据进行释放   堆区  手动开辟，手动释放！
	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}

	//年龄的指针
	int *m_Age;

};


void test01()
{
	Person p1(18);

	Person p2(20);

	Person p3(30);

	p3 = p2 = p1; //赋值操作

	cout << "Age of p1: " << *p1.m_Age << endl;

	cout << "Age of p2: " << *p2.m_Age << endl;

	cout << "Age of p3: " << *p3.m_Age << endl;
}

int main() {

	test01();

	int a = 10;
	int b = 20;
	int c = 30;

	c = b = a;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	system("pause");

	return 0;
}