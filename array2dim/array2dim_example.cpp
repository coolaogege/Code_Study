//二维数组的应用案例

#include <iostream>
#include <string>

using namespace std;

#define row  3  //定义行
#define col  3  //定义列

int main(){

    //Aarry_example

    // 第2种方式 
    int arr[row][col] = 
    {
        { 100,100,100 },   //代表第一行 
        { 90,50,100 },   //代表第二行
        { 60,70,80 }   //代表第三行
    };
    
    int sum = 0;
    string name[3] = { "A" ,"B" ,"C" };  //声明一个字符串数组

    //二维矩阵的输出打印
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        
            cout << arr[i][j] << "\t";  //水平制表符   对齐矩阵!
        }
        cout << name[i] << "grade:   " << sum << "\n" << endl;
        sum = 0;
    }
    
    system("pause");

    return 0;
}