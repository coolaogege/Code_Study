//一维数组的名称的用途：

// 1.可以统计整个数组在内存中的长度
// 2.可以获取数组在内存中的首地址


#include <iostream>

using namespace std;

int main(){

    //Aarry_name

    int arr[5] = {1,2,3,4,5};

    cout << sizeof(arr[0]) << endl; // 4  int类型 1个占用4字节
    cout << sizeof(arr) << endl;   // 20

    cout << arr << endl;      //0x61fef8 数组的首地址
    cout << &arr[0] << endl;      //0x61fef8 数组中第一个元素arr[0]的首地址    --- 前面有&  
    cout << &arr[1] << endl;      //0x61fefc 数组中第一个元素arr[1]的首地址

    cout << end(arr)-begin(arr) << "\n" << endl;      //计算数组的长度

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;  // 没有初始化的数据  值不确定！！
    }
    
    system("pause");

    return 0;
}