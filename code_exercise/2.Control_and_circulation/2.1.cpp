// Date : 2021.11.11
// Descibe: Find the maximum, minimum, and average  in numbers
// author : YA 


#include <iostream>

using namespace std;


int main()
{   
    int n = 0;

    int max , min; 
    int sum = 0;
    double avg;
    
    int k;

    cout << " Please input n : "  << endl;

    cin >> n ;

    cout << " Please input " << n << " numbers and end with enter : "  << endl;

    int count = 0;
    count = n ; 

    while (n > 0)
    {
        cin >> k ; 

        sum = sum + k;  

        if( count == n )
        {
            max = min = k;
        }

        if ( k > max)
        {
            max = k ;
        }

        if ( k < min )
        {
            min = k;
        }
        
        n--;
  
    }

    avg = (sum*1.0) / count ; // only in this way an get double 

    cout << " max : " << max <<  " min : " << min << "  avg :  " <<  avg << endl;
    
    system("pause");
    return 0;
}


