// 全局区
/* 	 ​
	   全局变量和静态变量存放在此.

​		全局区还包含了常量区, 字符串常量和其他常量也存放在此.

​		==**该区域的数据在程序结束后由操作系统释放**==. 
*/


#include <iostream>

using namespace std;

//全局变量 - global
int g_a = 10;
int g_b = 10;

//全局常量
const int c_g_a = 10;
const int c_g_b = 10;

int main() {

	//局部变量
	int a = 10;
	int b = 10;

	cout << "Partial a: " << (int)&a << endl;   // 6422284
	cout << "Partial b: " << (int)&b << endl;	// 6422280

	//全局变量
	cout << "Global a: " <<  (int)&g_a << endl;	// 4210692
	cout << "Global b: " <<  (int)&g_b << endl;	// 4210696

	

	//静态变量 - static
	static int s_a = 10;
	static int s_b = 10;

	cout << "static a: " << (int)&s_a << endl; // 4210700
	cout << "static b: " << (int)&s_b << endl; // 4210704

	// 字符串常量
	string hw = "hello world";

	cout << "String constant:  " << (int)&hw << endl; // 6422252

	//全局常量
	cout << "Global constant a: " << (int)&c_g_a << endl;  // 4214856
	cout << "Global constant b: " << (int)&c_g_b << endl;  // 4214860


	//局部常量 
	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "Partial constant a: " << (int)&c_l_a << endl; // 6422248
	cout << "Partial constant b: " << (int)&c_l_b << endl; // 6422244

	system("pause");

	return 0;
}