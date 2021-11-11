// 利用指针作为函数的参数 ， 可以修改 实参的值

#include <iostream>

using namespace std;

// 实现两个数的交换
void swap(int * p1 , int * p2)
{
    int temp = *p2;
    *p2 = *p1;
    *p1 = temp;
}


int main()
{
    int a = 10;
    int b = 20;

    cout << a << "  " << b << endl;

    swap(&a,&b);

    cout << a << "  " << b << endl;

    system("pause");
    return 0;
}