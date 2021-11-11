//continue 
//在循环语句中， 跳过本次循环中余下的还未执行的语句 进行下一次的循环

#include <iostream>

using namespace std;

int main(){

    //continue 

    int score = 0;
    
    cout << "Please input your score:" << endl;
    cin >> score;

    for (int i = 0; i < score; i++)
    {
        if (i % 2 == 0)
        {
            //break;    // 会直接退出循环！
            continue;
        }
        
        cout << i << endl;
    }
        
    system("pause");

    return 0;
}