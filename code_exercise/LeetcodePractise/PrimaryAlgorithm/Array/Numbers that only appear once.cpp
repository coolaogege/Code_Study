/* Date   : 2022.03.10
Descibe   : Given a non-empty array of integers, each element appears twice except one that appears only once.
            Find the element that appears only once

Note      : Has linear time complexity. Implemented without using extra space

author    : YA  */

#include <iostream>
using namespace std;


int singleNumber(int* nums, int numsSize){

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            /* code */
            if( nums[i] == nums [j] )
            {
                nums[i]=0;
            }
        }
    }

    for (int k = 0; k < numsSize; k++)
    {
        /* code */
        if (nums[k] == 1)
        {
            return nums[k];
        }
        
    }    

    return 0;
}


// Leetcode example
int Leetcode_singleNumber(int* nums, int numsSize)
{
    
}



int main(){

    int a[5] = {4,1,2,1,2};
    int *p = &a[0];
    int numsSize = 5;

    cout << singleNumber(p , numsSize) << endl;

    system("pause");
    return 0;

}