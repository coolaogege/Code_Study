// go to 
// 初级不太推荐使用  -- 后续 还在摸索

#include <iostream>

using namespace std;

int main(){

    //go to

    cout << "1,***" << endl;

    cout << "2,***" << endl;

    goto FLAG; //jump to FLAG

    cout << "3,***" << endl;

    cout << "4,***" << endl;

    FLAG :
    cout << "5,***" << endl;

    system("pause");

    return 0;
}