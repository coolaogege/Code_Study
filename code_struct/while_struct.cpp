//while 循环

#include <iostream>

#include <ctime> //时间系统头文件的一个包含

using namespace std;

// int main(){

//     //while  

//     int score = 0;
    
//     cout << "Please input your score:" << endl;
//     cin >> score;

//     while (score < 10)
//     {
//         score++;
//         cout << score << endl;
//     }

//     system("pause");

//     return 0;
// }

int main(){

    //while_example 

    srand( (unsigned int)time(NULL) ); //添加随机数种子 ， 利用当前系统的时间生成随机数 ，防止每次随机数都一样！

    int score = 0;
    int num = rand()%10 + 1; //生成0-9的随机数 and +1  ---- 1-10
    
    cout << "Please input your number in 0 to 10:" << endl;
    cin >> score;

    while (1)
    {
        if(score != num)
        {
            cout << "Error!" << endl;
            cout << "Please input your number in 0 to 10:" << endl;
            cin >> score;
        }
        else
        {
            cout << "Yeah!" << endl;
            break; //使用该关键字 可以退出当前循环
        }
    }

    system("pause");

    return 0;
}