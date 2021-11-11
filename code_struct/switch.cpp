//switch 选择

#include <iostream>

using namespace std;

int main(){

    //switch 选择 -- 分支判断 只能为整型 或者 是 字符型  不能是一个区间 
    //但结构清晰，执行效率高！
    //case 内如果没有 break  则会一直的向下执行！
    
    int score = 0;
    
    cout << "Please input your score:" << endl;
    cin >> score;


    switch(score)
    {
        case 1:
            cout << "1" << endl;
            break; // exit the branch
        case 2:
            cout << "2" << endl;  
            break; 
        default : // when no suitable branch , run this branch!
            cout << "None!" << endl;
            break;          
    }


   
    system("pause");

    return 0;

}