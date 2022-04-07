/* Date   : 2022.04.07
Descibe   : Given a string s , find its first distinct character and return its index . Returns -1 if not present.

Note      : None

author    : YA  */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


// 自制方法，这题没有做出来，遇到连续重复的情况不能解决！  例如  aaabbbb  
class Solution {
public:
    int firstUniqChar(string s) {
        size_t m = 0;
        if(end(s) - begin(s) == 1)
            return 0;
        for(auto i  = begin(s); i != end(s); ++i ){
            if(i != end(s)-1){
                i = i + m;
                m = 0;
            }
            for(auto j  = i+1; j != end(s); ){

                if( *i == *j){
                    ++m;
                    ++j;
                    continue;
                }
                if( (j == end(s) - 1 ) && m == 0 )  
                    return i - begin(s);
                ++j ;      
            }
        }
        return -1;
    }
};

// Leetcode example
// 对我的思路的改进，直接每个都从头遍历！！  时间复杂度很高！
// 别人用了哈希运算，不太会！！
class Leetcode_Solution {
public:
    int firstUniqChar(string s) {

        size_t len = s.size();
        if (len == 1) {
            return 0;
        }
        for (size_t i = 0; i < len; i++) {
            for (size_t j = 0; j < len; j++) {
                if (s[i] == s[j] && i != j) {
                    break;
                } 
                else if (j == len-1){
                    return i;
                }
            }
        }
        return -1;

    }
};


int main(){

    string s = "aabb";
    Solution solution;
    cout << solution.firstUniqChar(s) << endl;

    system("pause");
    return 0;

}