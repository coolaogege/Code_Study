// 堆区
//    由程序员分配释放,若程序员不释放,程序结束时由操作系统回收

//​	   在C++中主要利用 new 在堆区 开辟内存


#include <iostream>

using namespace std;


// 因为返回的是 地址 所以 使用  int *  ！！！
int * func()
{
    // 指针 本质也是一个局部变量 -- 位于栈上  
    // 指针 保存的数据是放在堆区！！！
    // 开辟在堆区 -- 声明一个变量----初值为10的整型   ----> 然后声明一个指针 指向该变量的地址！
    // 只是 把堆区的地址编号用指针 保存住了  -- 解引用  ---> 先是找到了指针 -- 指针指向的地址编号 -- 从而找到堆区对应地址的值
    int *p = new int(10); 

    return p; // return adress 
}

int main() {

    // 在堆区开辟数据
	int *p = func();

	cout << *p << endl; // 输出10  
	cout << *p << endl; // 输出10

	system("pause");

	return 0;
}