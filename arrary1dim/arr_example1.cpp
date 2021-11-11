// 计算数组的最大值

#include <iostream>

using namespace std;

int main(){

    //Aarry_example1

    int arr[5] = {125,236,375,104,95};

    int max = 0;

    for (int i = 0; i < 5; i++)
    {
        if ( max >= arr[i] )
        {   
           continue; 
        }
        else
        {
            max = arr[i];
        }  
    }
    cout << max << endl;
    
    system("pause");

    return 0;
}