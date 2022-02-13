

/* #### 4.7.5 虚析构和纯虚析构

多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码

解决方式：将父类中的析构函数改为**虚析构**或者**纯虚析构**

虚析构和纯虚析构共性：

* 可以解决父类指针释放子类对象
* 都需要有具体的函数实现

虚析构和纯虚析构区别：

* 如果是纯虚析构，该类属于抽象类，无法实例化对象



虚析构语法：

`virtual ~类名(){}`

纯虚析构语法：

` virtual ~类名() = 0;`

`类名::~类名(){}` */



/* 总结：

​	1. 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象

​	2. 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构

​	3. 只拥有纯虚析构函数的类也属于抽象类

   4. 直接写 虚析构就完事了！
*/


#include <iostream>

using namespace std;


class Animal {
public:

	Animal()
	{
		cout << "Animal constructor call" << endl;
	}
	virtual void Speak() = 0;

	//析构函数加上virtual关键字，变成虚析构函数  解决 子类 堆区 析构的问题！
	//virtual ~Animal()
	//{
	//	cout << "Animal virtual destructor call" << endl;
	//}

    // 纯虚析构函数  同样也能解决 子类 堆区 析构的问题！
    // 没有其他成员函数  只有这一个纯虚析构 也是无法实例化的
	virtual ~Animal() = 0;
};

// 这段代码  是因为  虚析构  和 纯虚析构  都需要 进行 函数声明和实现  
// 另外父类也可能在堆区开辟数据 因此需要进行析构
Animal::~Animal()
{
	cout << "Animal Pure virtual destructor call" << endl;
}

//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。

class Cat : public Animal {
public:
	Cat(string name)
	{
		cout << "Cat constructor call" << endl;
		m_Name = new string(name);  // 创建的堆区数据！
	}
	virtual void Speak()
	{
		cout << *m_Name <<  "cat are talking" << endl;
	}
	~Cat()  // 析构函数  用来释放数据
	{
		cout << "Cat destructor call" << endl;
		if (this->m_Name != NULL) {
			delete m_Name;
			m_Name = NULL;
		}
	}

public:
	string *m_Name;
};

void test01()
{
	Animal *animal = new Cat("Tom");
	animal->Speak();

	//通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
	//怎么解决？给基类增加一个虚析构函数
	//虚析构函数就是用来解决通过父类指针释放子类对象
	delete animal;
}

int main() {

	test01();

	system("pause");

	return 0;
}