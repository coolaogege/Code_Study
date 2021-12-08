/* #### 3.3.2 函数重载注意事项

* 引用作为重载条件
* 函数重载碰到函数默认参数 */

#include <iostream>

using namespace std;

//函数重载注意事项

//1、引用作为重载条件
void func(int &a)
{
	cout << "func (int &a)" << endl;
}

void func(const int &a)
{
	cout << "func (const int &a)" << endl;
}


//2、函数重载碰到函数默认参数
void func2(int a, int b = 10)
{
	cout << "func2(int a, int b = 10)" << endl;
}

void func2(int a)
{
	cout << "func2(int a)" << endl;
}


int main() {

    int a = 10;

	func(a);  // func (int &a) -- can read/write
    func(10); // only in this way  / first way is illegal

    //func2(10);  // mutiple ways can match ,so occur error
    func2(10,20); // func2(int a, int b = 10)

	system("pause");

	return 0;
}