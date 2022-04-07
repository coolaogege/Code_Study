/* Date   : 2022.03.15
Descibe   : Given an array prices , where prices[i] represents the price of the stock on day i,
            On each day, you may decide to buy and/or sell stock. You can only hold at most one stock at any one time.
            You can also buy it and sell it the same day.Return the maximum profit you can get.

Note      : None.

author    : YA  */

#include <iostream>
using namespace std;


int maxProfit(int* prices, int pricesSize){

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