// Date : 2021.11.11
// Descibe: How many 3 digits without repeated digits can be composed of statistic numbers 0-9
// author : YA 

#include <iostream>

using namespace std;


int main()
{  
    int ge = 0;
    int shi = 0;
    int bai = 0;

    int num = 0;
    int count = 0;

    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(j != i)
            {
                for (int m = 0 ; m < 10; m++)
                {
                    if (m != j and m != i)
                    {
                        num = i * 100 + j * 10 + m ;
                        count++;
                        
                        cout << num << "   ";

                        if (count % 10 == 0)
                        {
                            cout << endl;
                        }
                    }    
                }
            }
        }
        
    }
    
    system("pause");
    return 0;
}


