// Date : 2021.11.12
// Descibe: Roll the dice 10000 times, count the number of times each point is obtained
// author : YA 

#include <iostream>
#include <ctime> //时间系统头文件的一个包含

using namespace std;


// statistics_function
int statistics(int num)
{
    int sum = 0; 

    for (int i = num; i > 0; i--)  // the core of tis code
    {

        int score = rand()%6 + 1; //生成0-5的随机数 and +1  ---- 1-6
        sum += score;
        cout << i << " score :" << score << endl; 
    }

    return sum;
}

int main()
{     
    srand( (unsigned int)time(NULL) ); //添加随机数种子 ， 利用当前系统的时间生成随机数 ，防止每次随机数都一样！

    int times = 0; 
    int sum = 0;
    cout << " Please input your roll times : " << endl;
    cin >> times ;    
    sum = statistics(times); 
    cout << " Sum :"  << sum << endl;  

  
    system("pause");
    return 0;
}


