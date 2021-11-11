//for 循环

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
        cout << score + i << endl;
    }
        
    system("pause");

    return 0;
}

