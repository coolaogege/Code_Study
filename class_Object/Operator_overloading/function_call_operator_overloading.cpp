
/* #### 4.5.6 函数调用运算符重载


* 函数调用运算符 ()  也可以重载
* 由于重载后使用的方式非常像函数的调用，因此称为仿函数
* 仿函数没有固定写法，非常灵活 */


#include <iostream>

using namespace std;


class MyPrint
{
public:
    // 重载函数调用运算符 operator()   (string text) ---> 形参
	void operator()(string text)
	{
		cout << text << endl;
	}

};

void test01()
{
	//重载的（）操作符 也称为仿函数
	MyPrint myFunc;
    // 调用了 operator()(string text)  ---> 输出 hello world
	myFunc("hello world");
}


class MyAdd
{
public:
    // 有返回值时  int 代表返回数据类型 
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void test02()
{
	MyAdd add;
    // 调用了 int operator()(int v1, int v2)
	int ret = add(10, 10);
	cout << "ret = " << ret << endl;

	//匿名对象调用  MyAdd() (100, 100)
	cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
}

int main() {

	test01();
	test02();

	system("pause");

	return 0;
}