/* #### 4.2.7 类对象作为类成员

C++类中的成员可以是另一个类的对象，我们称该成员为 对象成员


例如：

```C++
class A {}
class B
{
    A a；
}
```

B类中有对象A作为成员，A为对象成员

那么当创建B对象时，A与B的构造和析构的顺序是谁先谁后？ */


#include <iostream>

using namespace std;

class Phone
{
public:
	Phone(string name)
	{
		m_PhoneName = name;
		cout << "Phone constructor" << endl;
	}

	~Phone()
	{
		cout << "Phone Destructor" << endl;
	}

	string m_PhoneName;

};


class Person
{
public:

	//初始化列表可以告诉编译器调用哪一个构造函数
	Person(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "Person constructor" << endl;
	}

	~Person()
	{
		cout << "Person Destructor" << endl;
	}

	void playGame()
	{
		cout << m_Name << " Use" << " " << m_Phone.m_PhoneName << " ! " << endl;
	}

	string m_Name; // 姓名
	Phone m_Phone; // 手机

};
void test01()
{
	//当类中成员是其他类对象时，我们称该成员为 对象成员
	//构造的顺序是 ：先调用对象成员的构造，再调用本类构造
	//析构顺序与构造相反
	Person p("zhangsan" , "iphoneX");
	p.playGame();

}


int main() {

	test01();

	system("pause");

	return 0;
}