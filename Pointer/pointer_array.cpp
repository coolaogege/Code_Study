// 指针和数组
// 作用 ： 利用指针 访问数组中元素


#include <iostream>

using namespace std;

int main()
{
    // create a array
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

    // create a pointer point array
    int * p = arr;  // arr --- the adress of array    

    //显示数组的第一个数据！
    cout << *p << endl; 

    // 访问数组的第二个数据！
    p++;  // p 为四个字节  p++ 即地址加4  代表数组第二个数据的地址  int型数组 一个占4字节！
    cout << &arr[1] << endl;
    cout << p << endl; 
    cout << *p << endl;

    p = arr;
    // 使用指针遍历整个数组！  --- 这种方式 容易使指针越界！！
    for (int i = 0; i < 10; i++)
    {
        cout << *p << " ";
        p++;
    }

    cout <<"\n"<< endl;

    p = arr;
    // 使用指针遍历整个数组！  --- 另一种方式
    for (int i = 0; i < 10; i++)
    {
        cout << *(p + i )<< " ";
    }

    cout <<"\n"<< endl;

    system("pause");
    return 0;
}