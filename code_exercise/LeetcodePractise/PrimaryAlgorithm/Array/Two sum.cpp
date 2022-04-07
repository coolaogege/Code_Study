/* Date   : 2022.03.10
Descibe   : Given an integer array nums and an integer target value target, 
            please find the two integers in the array that are the target value target and return their array indices

Note      : It can be assumed that each input corresponds to only one answer. 
            However, the same element in the array cannot be repeated in the answer

author    : YA  */

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> newnums;
        for (auto i  = begin(nums); i != end(nums); ++i){
            for(auto j = begin(nums); j != end(nums); ++j){
                if ( (*i + *j == target) && i != j)
                {
                    // i迭代器，代表当前数组的第几个元素的指针，减去初始的指针，即为当前元素的下标
                    newnums.push_back(i - begin(nums)); 
                }               
            }
        }
        return newnums;
    }
};


int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    for (int i = 0; i < numsSize; i++)
    {
        /* code */
        for (int j = 0; j < numsSize; j++)
        {
            /* code */
            if ( (nums[i] + nums[j] == target ) && (i != j ) )
            {
                /* code */
                *returnSize = i;
                * (++returnSize) = j;
            }           
        }        
    }
}


// Leetcode example
int* Leetcode_twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    
}



int main(){

    int a[4] = {11,2,7,15};
    int *p = &a[0];
    int numsSize = 4;
    int ret[2] = {0};
    int *retvalue = &ret[0];

    twoSum(p , 4 , 9 , retvalue);
    
    for (int i = 0; i < 2; retvalue++,i++)
    {
        /* code */
        cout << *retvalue << "  " ;
    }
    cout << endl;

    system("pause");
    return 0;

}