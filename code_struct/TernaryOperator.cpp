//三目运算符

#include <iostream>

using namespace std;

int main(){

    //三目
    
    int a = 10;
    int b = 20;
    int c = 0;

    c = (a > b ? a : b);  //返回b的值 c=20

    cout << c << endl;

    a > b ? a : b = 10;  // 给b赋值 ---可以用来继续赋值！！

    cout << a << endl;
    cout << b << endl;

    
    system("pause");

    return 0;

}