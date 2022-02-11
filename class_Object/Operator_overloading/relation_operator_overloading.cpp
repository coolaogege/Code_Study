

/* #### 4.5.5 关系运算符重载


**作用：**重载关系运算符，可以让两个自定义类型对象进行对比操作 */


#include <iostream>

using namespace std;


class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	};

	bool operator==(Person & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(Person & p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	string m_Name;
	int m_Age;
};

void test01()
{
	//int a = 0;
	//int b = 0;

	Person a("SunWuKong", 18);
	Person b("SunWuKong", 18);

	if (a == b)
	{
		cout << "a and b are equal" << endl;
	}
	else
	{
		cout << "a and b are not equal" << endl;
	}

	if (a != b)
	{
		cout << "a and b are not equal" << endl;
	}
	else
	{
		cout << "a and b are equal" << endl;
	}
}


int main() {

	test01();

	system("pause");

	return 0;
}