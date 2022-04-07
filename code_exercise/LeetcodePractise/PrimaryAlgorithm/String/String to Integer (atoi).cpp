/* Date   : 2022.04.07
Descibe   : Please implement a myAtoi(string s) function that converts a string to a 32-bit signed integer (similar to the atoi function in C/C++).

Note      : Whitespace characters in this question only include the space character ' ' .
            Do not omit any other characters except leading spaces or the rest of the string after a number.

author    : YA  */

#include <iostream>
#include <vector>

using namespace std;

// 这题感觉太难了！！！！


class Solution {
public:
    int myAtoi(string s) {
        vector<char> str;
        for(auto &r : s){
            if( ('0'<= r && r <= '9' ) || r == '+' || r == '-'){
               str.push_back(r); 
            }
        }
        for(auto &n : str){

        }

    }
};

// Leetcode example




int main(){

    string s = "4193 with words";
    Solution solution;


    system("pause");
    return 0;

}