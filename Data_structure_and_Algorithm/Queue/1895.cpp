// Date : 2022.2.19
// Descibe: 利用栈的思想：斐波纳契数列
// author : YA

/* Note : 这里使用的是queue的容器   */

#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;



int main()
{
    int x, y, n;
    queue<int> c;
    cin >> n;
    while (n--)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> y;
            c.push(y);
        }
        else if (x == 2)
        {
            if (c.empty())
            {
                cout << "no" << endl;
                break;
            }
            else
            {
                cout << c.front() << endl;
                c.pop();
            }
        }
        else
            cout << c.size() << endl;
        
    }

    system("pause");

    return 0;
}