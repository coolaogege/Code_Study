// if  三目 switch
#include <iostream>

using namespace std;

int main(){

    //选择结构
    
    int score = 0;
    cout << "Please input your score:" << endl;
    cin >> score;
    
    if(score > 50)
    {
        cout << "Good!" << endl;

    }
    else if(score > 40)
    {
        cout << "normal!" << endl;
    }
    else
    {
        cout << "Poor!" << endl;
    }
    
    system("pause");

    return 0;

}