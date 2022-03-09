// Date : 2022.2.19
// Descibe: 利用栈的思想：斐波纳契数列
// author : YA

/* Note : 目前此代码使用的是递归的方式，但递归的底层就是用到了栈这种数据结构，因此可以使用栈完成此任务
          留个坑   */              

#include <iostream>

#include <string>

using namespace std;

int main()

{

    int f(int);

    int N;

    cin >> N;

    for (int i = 1; i <= N; i++)

        cout << f(i) << " ";
    
    system("pause");
    return 0;
}

int f(int x)

{

    if (x == 1 || x == 2)

    {

        return 1;
    }

    else

        return f(x - 1) + f(x - 2);
}
