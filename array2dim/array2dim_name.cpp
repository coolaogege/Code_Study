//二维数组 数组名

//查看二位数组所占的内存空间
//获取二维数组的首地址

#include <iostream>

using namespace std;

#define row  4  //定义行
#define col  4  //定义列

int main(){

    //Aarry_name

    int arr[row][col] = 
    {
        { 1,2,3,4 },   //代表第一行 
        { 5,6,7,8 },   //代表第二行
        { 9,8,7,6 },   //代表第三行
        { 5,4,3,2 }    //代表第四行
    };

    cout << sizeof(arr) << "\n" << endl;  //输出64 -- 16*4 16元素  每元素4字节
    cout << sizeof(arr[0]) << "\n" << endl; //输出16 -- 4*4 第一行4元素  每元素4字节
    cout << sizeof(arr[0][0]) << "\n" << endl; //输出4 -- 1*4 第一个元素  一个元素4字节
    cout << sizeof(arr)/sizeof(arr[0]) << "\n" << endl; //输出行数 4
    cout << sizeof(arr[0])/sizeof(arr[0][0]) << "\n" << endl; //输出列数 4

    cout << arr << "\n" << endl; //输出 二维数组-首地址
    cout << arr[1] << "\n" << endl; //输出 二维数组第2行-首地址
    cout << &arr[1][0] << "\n" << endl; //输出 二维数组第2行第1个元素-首地址  ---- 具体到 数组的一个元素取址 应该使用 & 

    //二维矩阵的输出打印
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
           cout << arr[i][j] << " ";  // 没有初始化的数据  值不确定！！
        }
        cout << "\n" << endl;
    }
    
    system("pause");

    return 0;
}