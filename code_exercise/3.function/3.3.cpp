// Date : 2021.11.12
// Descibe: Write a function to determine whether a number is prime, and find the prime number within 1-1000
// author : YA 

// tips : 判断n是否整除（求余是否等于0）大于1而小于sqrt(n)中的任何一个数，如果有则不是素数，否则是素数

#include <iostream>
#include <cmath>

using namespace std;


// determine_prime_function
int determine_prime(int num)
{
    for (int i = 2; i < sqrt(num); i++)  // the core of tis code
    {
        if( (num % i) == 0 )  // note add ()
        {
            return  0;
        }        
    }

    return 1;
}

int main()
{     

    int number = 1; 

    bool isFlag ;

    while (number !=  0)
    {
        cout << " Please input number : " << endl;
        cin >> number ;

        isFlag = determine_prime(number); // 调用判断是否是素数的函数  
        
        if(  isFlag )
             cout << "is not a primer ! " << endl; 
        else
             cout << "is  a primer ! " << endl; 
    }
  
    system("pause");
    return 0;
}


