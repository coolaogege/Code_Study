// Date : 2021.11.11
// Descibe: It is known that there are 30 chickens and rabbits in total, with 90 fingers in their feet.
//          Calculate how many chickens and rabbits each have!
// author : YA 

#include <iostream>

using namespace std;


int main()
{  
    int head = 30;
    int feet = 90;

    int chicken = 0;
    int rabbit  = 0;

	//calculate
	chicken = (4 * head - feet) / 2;
	rabbit = head - chicken;
	cout <<  chicken << "   " << rabbit << endl;

    
    system("pause");
    return 0;
}


