/* Date   : 2022.04.07
Descibe   : Write a function that reverses the input string. The input string is given as a character array s.

Note      : Don't allocate extra space for another array, you have to modify the input array in place, 
            use O(1) extra space to solve this problem

author    : YA  */

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        // 双指针
        auto i  = begin(s), j = end(s)-1;
        // No element or Only one element
        // if(i == j)
        //     return ;
        for ( ; i <= j ; ++i , --j){
            auto temp = *i;
            *i = *j ; 
            *j = temp;
        }
    }
};


// Leetcode example




int main(){



    system("pause");
    return 0;

}