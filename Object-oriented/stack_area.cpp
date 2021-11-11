// ​	**栈区：**

/* ​		
       由编译器自动分配释放, 存放函数的参数值,局部变量等

​		注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
 */


#include <iostream>

using namespace std;


// 因为返回的是 地址 所以 使用  int *  ！！！
int * func()
{
    int a = 10; // partial variable  --  存放在栈区  栈区的数据在函数执行之后就会自动释放   --  不要返回栈区局部变量的地址！
    return &a; // return adress of variable a
}

int main() {

	int *p = func();

	cout << *p << endl; // 直接报错！！ 不能这么使用  
	cout << *p << endl;

	system("pause");

	return 0;
}