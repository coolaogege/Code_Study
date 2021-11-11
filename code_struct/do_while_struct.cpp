//do_while 循环

#include <iostream>

#include <ctime> //时间系统头文件的一个包含

using namespace std;

int main(){

    //do_while  

    int score = 0;
    
    cout << "Please input your score:" << endl;
    cin >> score;

    // will output 11 when input 10  
    // will run one time first then judge
    do
    {
        score++;
        cout << score << endl;           
    } 
    while (score < 10);  
    
    system("pause");

    return 0;
}

