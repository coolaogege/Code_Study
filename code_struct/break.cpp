//break 语句
//用于跳转选择结构或者循环结构

//switch条件语句中  作用是 终止case并跳出switch
//出现在循环语句中  作用是 跳出当前的循环语句
//出现在嵌套循环中  跳出内循环

#include <iostream>

#include <ctime> //时间系统头文件的一个包含

using namespace std;

int main(){

    //break 

    int score = 0;
    
    cout << "Please input your score:" << endl;
    cin >> score;

    for (int i = 0; i < score; i++)
    {

        // if(i == 5)
        // {
        //     break;
        // }

        for (int j = 0; j < 10; j++)
        {
            if(j == 5)
            {
                break;
            }
            cout << "*  ";
        }
        cout << "\n" << endl;
    }
        
    system("pause");

    return 0;
}

