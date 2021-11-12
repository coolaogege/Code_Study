// Date : 2021.11.12
// Descibe: A function to find the sum of the digits of an integer
// author : YA 

#include <iostream>
#include <string>
#include<math.h>

using namespace std;


// add_function
int add(int num)
{
    int length; 
    int sum = 0; 

    string str = to_string(num);   // 整型转换为字符串

    cout << str << endl;

    length = str.length();       // 计算字符串长度  -- 要加上括号!!

    cout << length << endl;

    cout << endl;

    for (int i = length; i > 0; i--)  // the core of tis code
    {
        sum += num%10;
        num = num/10;
        cout << sum << "   " << num << endl;
    }

    return sum;
}

int main()
{     
    int num = 0;
    int sum = 0;
    cout << " Please input your num : " << endl;
    cin >> num ;    
    sum = add(num); 
    cout << " Sum :"  << sum << endl;  

  
    system("pause");
    return 0;
}


