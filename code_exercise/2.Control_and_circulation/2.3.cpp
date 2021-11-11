// Date : 2021.11.11
// Descibe: Number of eligible
// author : YA 

#include <iostream>

using namespace std;


int main()
{  
    int arr_5_2[100] = {};
    int arr_9[100] = {} ;

    int m = 0;
    int n = 0;

    for (int i = 1; i < 101; i++)
    {
        if(i%5 == 2)
        {
            arr_5_2[m] = i;
            m++;
        }

         if(i%9 == 0)
        {
            arr_9[n] = i;
            n++;
        }     
    }

    for (int i = 0; i < m; i++)
    {
        cout << arr_5_2[i]  << "   ";  
    }
        cout << endl; 
    
    for (int i = 0; i < n; i++)
    {
        cout << arr_9[i]  << "   ";  
    }    
        cout << endl; 

    
    system("pause");
    return 0;
}


