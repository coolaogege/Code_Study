// for 循环进行嵌套

#include <iostream>

#include <ctime> //时间系统头文件的一个包含

using namespace std;

int main(){

    //for  

    int score = 0;
    
    cout << "Please input your score:" << endl;
    cin >> score;

    for (int i = 0; i < score; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << "*  ";
        }
        cout << "\n" << endl;
    }
        
    system("pause");

    return 0;
}

