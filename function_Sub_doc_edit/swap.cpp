#include "swap.h"


//如果不需要返回值 声明的时候写void
void swap(int num1 , int num2)
{
    cout << num1 << "  " << num2 << endl;

    int temp = 0;
    temp = num1;
    num1 = num2;
    num2 = temp;

    cout << num1 << "  " << num2 << endl;

    //return;  //---- 返回值不需要的时候，可以不写return
}