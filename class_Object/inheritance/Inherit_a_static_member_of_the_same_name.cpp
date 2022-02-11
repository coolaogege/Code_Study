
/* #### 4.6.6 继承同名静态成员处理方式



问题：继承中同名的静态成员在子类对象上如何进行访问？



静态成员和非静态成员出现同名，处理方式一致

静态成员变量  所有对象都共享同一份数据 编译阶段就分配内存 类内声明 类外初始化
静态成员函数  只能访问 静态的成员变量  不能访问非静态成员变量 所有对象都共享同一份函数实例 


- 访问子类同名成员   直接访问即可
- 访问父类同名成员   需要加作用域 */


// > 总结：同名静态成员处理方式和非静态处理方式一样，只不过有两种访问的方式（通过对象 和 通过类名）


#include <iostream>

using namespace std;


class Base {
public:
    // static 
	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - static void func(int a)" << endl;
	}

	static int m_A;
};

// 类内声明 类外初始化
int Base::m_A = 100;

class Son : public Base {
public:
	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
	static int m_A;
};

// 类内声明 类外初始化
int Son::m_A = 200;

//同名成员属性
void test01()
{
	//通过对象访问
	cout << "Access by object: " << endl;
	Son s;
	cout << "Son  -- m_A = " << s.m_A << endl;
	cout << "Base -- m_A = " << s.Base::m_A << endl;

	//通过类名访问
	cout << "Access by class name: " << endl;
	cout << "Son  -- m_A = " << Son::m_A << endl;
	cout << "Base -- m_A = " << Son::Base::m_A << endl;
}

//同名成员函数
void test02()
{
	//通过对象访问
	cout << "Access by object: " << endl;
	Son s;
	s.func();
	s.Base::func();
    s.Base::func(100);

    //通过类名访问
	cout << "Access by class name: " << endl;
	Son::func();
	Son::Base::func();
	//出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问
	Son::Base::func(100);
}


int main() {

	test01();
	test02();


    // 静态变量 所有对象共享此数据  下面给出了实例
    Son s;
    cout << s.m_A << endl;  // 200  -- 初始化的值
    s.m_A = 10 ;

    Son s2;
    cout << s2.m_A << endl; // 10   -- 值为更改过后的值
    


	system("pause");

	return 0;
}