#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    // n (1 <= m <= n <= 1000000000)
    // cout << sizeof(int) << endl;   // 4*8 = 32  2^31  2147483648  enough!
    int m, n; // m -- 节点    n -- 最大节点数
    while (cin >> m >> n)
    {
        // 当最后一行为 0 0 时结束
        if (n == 0 && m == 0)
        {
            break; // 跳出循环
        }

        // p .....  q
        int p = 0, q = 0; // p start of every row      q end of every row
        double temp = 0.0; // 中间值
        int count = 1; //行数
        bool state = false; // 记录节点所在位置 左侧还是右侧
        int rightNode = 0; // 返回结果
        int leftNode = 0;  // 返回结果

        count = ceil(log(n + 1) / log(2));  // 取n个节点 树最高度 行
        int m_row = ceil(log(m + 1) / log(2)); // 节点m对应的行数

        p = pow(2 , m_row-1);
        q = p * 2 - 1;
        temp = (p + q) / 2.0;
        
        if(m > temp)  // 确定m节点所处的位置 偏左还是右
            state = true;
        else
            state = false;

        cout << count << "  " << m_row << "  "<< temp << " " << state << endl;

        p = 1; 
        for (int i = 2; i <= count; i++)  // 遍历每一层
        {
            p = pow(2 , i-1);
            q = p * 2 - 1;
            temp = (p + q) / 2.0;

            cout << i << "  " << p << "  " << q << " " << temp << endl;  // 打印每一层的 起始  中间 结束 三个值

            // 遍历该行  记录满足条件的个数
            for(int j = p; j <= q; j++ ){
                // cout << j << endl;
                if (state){
                    if (j > temp && j <= n)
                        rightNode+=1;
                }
                else
                    if (j < temp && j <= n)
                        leftNode+=1;         
            }
            p = q = 0;
        }

        if (state)
            cout <<  rightNode << endl;
        else
            cout <<  leftNode << endl;

        rightNode = leftNode = 0;    
    }

    system("pause");
    return 0;
}