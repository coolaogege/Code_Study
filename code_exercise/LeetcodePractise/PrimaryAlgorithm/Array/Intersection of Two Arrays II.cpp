/* Date   : 2022.03.29
Descibe   : Given two integer arrays nums1 and nums2 , please return the intersection of the two arrays as an array. 
            The number of occurrences of each element in the returned result should be the same as the number of times the element appears in both arrays 
            (if the number of occurrences is inconsistent, the smaller value is considered).
            The order of output results can be ignored.

Note      : None

author    : YA  */

#include <iostream>
#include <vector>

using namespace std;


 
/*快排C++实现*/
void quickSort(vector<int> &arr, int bgn, int end)  //arr must be the reference of real param
{
    //数组arr空or仅有一个元素则退出
    if (bgn >= end - 1)
        return;

    int lindex = bgn;
    int rindex = end - 1;
    int std = arr[lindex];
    while (lindex < rindex)
    {
        while (lindex < rindex)
        {
            if (arr[rindex] < std)
            {
                arr[lindex++] = arr[rindex];
                break;
            }
            --rindex;
        }

        while (lindex < rindex)
        {
            if (arr[lindex] >= std)
            {
                arr[rindex--] = arr[lindex];
                break;
            }
            ++lindex;
        } 
    }

    arr[lindex] = std;
    quickSort(arr, bgn, lindex);
    quickSort(arr, rindex + 1, end);
}



class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> newnums;
        // 先进行两数组的排序
        // 注意这里的快排，他的输入，看程序，最后会自己减一
        quickSort(nums1, 0, nums1.size());
        quickSort(nums2, 0, nums2.size());

        int index1 = 0;
        int index2 = 0;
        // 容器遍历进行对比
        for (auto i  = begin(nums1) + index1; i != end(nums1); ++i){
            for(auto j = begin(nums2) + index2; j != end(nums2); ++j){               
                if ( *i == *j )
                {
                    // 当第二数组只有一个元素的情况
                    if ( (j + 1) == end(nums2))
                    {
                        /* code */
                        newnums.push_back(*i); 
                        return  newnums;
                    }
                    else
                    {
                    //
                    index1 =  i - begin(nums1) + 1;
                    index2 =  j - begin(nums2) + 1;
                    newnums.push_back(*i); 
                    break;
                    }
                }               
            }
        }
        return newnums;
    }
};


// Leetcode example
class LeetcodeSolution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> newnums;

        //处理边界条件
        if(nums1.size() == 0 || nums2.size() == 0){  
            return newnums;
        }

        // 先进行两数组的排序
        // 注意这里的快排，他的输入，看程序，最后会自己减一
        quickSort(nums1, 0, nums1.size());
        quickSort(nums2, 0, nums2.size());

        auto i =nums1.begin();
        auto j =nums2.begin();

        while( (i != nums1.end())  && (j != nums2.end()) ){
            if(*i == *j){
                newnums.push_back(*i); 
                i++;
                j++;
            }
            else if(*i < *j){
                i++;
            }
            else{
                j++;
            }
        }
        return newnums;
    }
};


int main(){

    vector<int> nums1;
    vector<int> nums2;

    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(2);
    nums1.push_back(1);

    nums2.push_back(2);

    cout << nums1.size() <<  endl;
    
    quickSort(nums1, 0, nums1.size());
    quickSort(nums2, 0, nums2.size());   

    for (auto i  = begin(nums1); i != end(nums1); ++i){
        cout << *i  << "   ";

    }
    cout << endl;

    for (auto j  = begin(nums2); j != end(nums2); ++j){
        cout << *j << "   ";

    }
    cout << endl;

    system("pause");
    return 0;

}