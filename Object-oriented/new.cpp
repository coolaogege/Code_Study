// new 关键词
/* 
        C++中利用==new==操作符  在堆区开辟数据

        堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符  ==delete

        语法：` new 数据类型`

        利用new创建的数据，会返回该数据对应的类型的指针 
*/



#include <iostream>

using namespace std;


// 因为返回的是 地址 所以 使用  int *  ！！！
int * func()
{
    // new创建的数据，会返回该数据对应的类型的指针！
    // 只是 把堆区的地址编号用指针 保存住了  -- 解引用  ---> 先是找到了指针 -- 指针指向的地址编号 -- 从而找到堆区对应地址的值
    int *p = new int(10); 

    return p; // return adress 
}

void test01()
{
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;

    // 释放 堆区的数据
    delete p;

    cout << *p << endl;
}


// 在堆区开辟一个数组 用new
void test02()
{
    // 语法 -- [10] 代表有10个元素
    int *arr = new int[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 100 ; // 赋值 100 - 109
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

    // 释放数组  ---- 必须加[]
    delete[]  arr;

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    
}

int main() {

    test01();  

    test02(); 

	system("pause");

	return 0;
}