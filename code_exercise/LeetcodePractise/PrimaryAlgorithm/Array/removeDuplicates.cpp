/* Date   : 2022.03.11
Descibe   : Given an array nums in ascending order, please delete the repeated elements in place,
            so that each element appears only once, and return the new length of the deleted array.
            The relative order of elements should be consistent.

Note      : The input array must be modified in-place and done using O(1) extra space. 
            Implemented without using extra space.

author    : YA  */

#include <iostream>
using namespace std;


int removeDuplicates(int* nums, int numsSize){
    int newnums[31000] = {0};
    newnums[0] = nums[0];
    int k = 0;
    for (int i = 1; i < numsSize; i++)
    {
        /* code */
        if (nums[i] != nums[0] && nums[i] != newnums[k])
        {
            /* code */
            k += 1; 
            newnums[k] = nums[i];           
        }        
    }
    for (int i = 0; i <= k; i++)
    {
        /* code */
        nums[i] = newnums[i];
    }
    
    return k+1;
}


// Leetcode example
// 双指针！
int Leetcode_removeDuplicates(int* nums, int numsSize)
{
    int *left,*right;
    left = nums;
    right = &nums[1];
    int k = 1;

    while( numsSize > 1)
    {
        /* code */
        if( *left != *right)
        {
            left++;
            k++;
            *left = *right;
        }
        right++; 
        numsSize -= 1;       
    }
    return k;
}



int main(){

    int a[5] = {1,1,2};
    int *p = &a[0];
    int numsSize = 3;

    // cout << removeDuplicates(p , numsSize) << endl;
    cout << Leetcode_removeDuplicates(p , numsSize) << endl;

    system("pause");
    return 0;

}