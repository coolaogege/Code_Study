
/* #### 4.6.4 继承中构造和析构顺序



子类继承父类后，当创建子类对象，也会调用父类的构造函数



问题：父类和子类的构造和析构顺序是谁先谁后？ */


#include <iostream>

using namespace std;


class Base 
{
public:
	Base()
	{
		cout << "Base_Constructor" << endl;
	}
	~Base()
	{
		cout << "Base_Destrucutor" << endl;
	}
};

class Son : public Base
{
public:
	Son()
	{
		cout << "Son_Constructor" << endl;
	}
	~Son()
	{
		cout << "Son_Destrucutor" << endl;
	}

};


void test01()
{
	//继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反，即  先调用子类析构函数，再调用父类析构函数
	Son s;
}

int main() {

	test01();

	system("pause");

	return 0;
}