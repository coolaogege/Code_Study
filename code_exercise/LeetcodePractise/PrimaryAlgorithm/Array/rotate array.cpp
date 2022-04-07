/* Date   : 2022.03.11
Descibe   : Given an array, rotate the elements in the array k positions to the right, where k is a non-negative number.

Note      : Come up with as many solutions as possible, there are at least three different ways to solve this problem.

author    : YA  */

#include <iostream>
using namespace std;

#include<vector>

// time out

// void rotate(int* nums, int numsSize, int k){

//     for (int i = 0; i < k; i++)
//     {
//         int temp = nums[numsSize - 1];
//         for (int j = numsSize - 1; j > 0; j--)
//         {
//             /* code */
//             nums[ j ] = nums[j - 1];
//         }
//         nums[0] = temp;
//     } 
         
// }


// Leetcode example1
// reverse arrary operate
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start++] = nums[end];
        nums[end--] = temp;
    }
}

void rotate(int* nums, int numsSize, int k){

    // Key of this operate
    k = k%numsSize;

    reverse(nums , 0 , numsSize - 1);
    reverse(nums , 0 , k -1 );
    reverse(nums , k , numsSize - 1 );

}


// Leetcode example2
void Leetcode_rotate(vector<int>& nums, int k) {
    int len=nums.size();
    k%=len;
    if(k==0||len==1) return ;
    int temp;        
    temp=nums[0];
    int count = 0;
    for(int i=k,cnt=0;cnt<len;i+=k,cnt++)
    {
        int t=nums[i%len];
        nums[i%len]=temp;
        temp=t;
        if(i%len==count) 
        {
            count++;
            i = count;
            temp = nums[(i) % len];
        }
    }
    
}



int main(){

    int a[7] = {1,2,3,4,5,6,7};
    int *p = &a[0];
    int numsSize = 7;

    rotate(p , 7 , 3);
    for (int i = 0; i < numsSize; i++)
    {
        /* code */
        cout << a[i] << "  " ;
    }
    
    cout << endl ;

    system("pause");
    return 0;

}