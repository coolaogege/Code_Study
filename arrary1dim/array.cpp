//数组

// 所谓数组 就是 一个集合  里面存放了相同类型的数据元素

// Features 1 : The element of this array has the same type of data     -相同数据类型
// Features 2 : The array is composed of consecutive memory locations   -连续内存位置


//一维数组的定义的 三种方式 ：
// 1. 数据类型 数组名[数组长度];
// 2. 数据类型 数组名[数组长度] = {值1 , 值2 ...};
// 3. 数据类型 数组名[]  = {值1 , 值2 ...};


#include <iostream>

using namespace std;

int main(){

    //Aarry

    // 第1种方式
    // int arr[5];
    // arr[0] = 10 ;

    // 第2种方式
    // int arr[5] = {10,11,12,13,14};

    //第3种方式
    int arr[] = {10,11,12};

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;  // 没有初始化的数据  值不确定！！
    }
    
    system("pause");

    return 0;
}