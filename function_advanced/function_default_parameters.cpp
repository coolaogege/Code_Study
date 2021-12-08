// ## 3 函数提高

// ### 3.1 函数默认参数

// 在C++中，函数的形参列表中的形参是可以有默认值的。

// 语法：` 返回值类型  函数名 （参数= 默认值）{}`


#include <iostream>

using namespace std;

int func(int a, int b = 10, int c = 10) {
	return a + b + c;
}

//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
	return a + b;
}

int main() {

	cout << "ret = " << func(20, 20) << endl;  // 传了  就用自己的数据
	cout << "ret = " << func(100) << endl;    // 没传  就用默认的值
	cout << "ret = " << func2() << endl;

	system("pause");

	return 0;
}

