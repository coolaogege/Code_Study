// Date : 2021.11.11
// Descibe: Sort by multiple numbers
// author : YA 



#include <iostream>

using namespace std;


int main()
{  
    int max , min;

    int a , b;

    while (1)
    {
        cout << " Please input a pair of numbers : "  << endl;  

        cin >> a >> b;

        if ( a > b)
            cout << " min : " << b <<  " max : " << a  << endl;
        else if(a < b)
            cout << " min : " << a <<  " max : " << b  << endl;
        else
            break;
    }

    cout << " a = b  " << endl;
    
    system("pause");
    return 0;
}


