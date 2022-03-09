#include <iostream>
using namespace std;


#define maxLen 255

// 串的顺序存储方式 数组
typedef struct 
{
    char ch[maxLen + 1];        // 存储串的一维数组
    int  length;                // 串的当前长度
}SString;


// BF算法   从头开始进行查找
int IndexBF(SString S , SString T){
    int i = 1, j = 1;
    // 在有效范围内进行搜索
    while(i <= S.length && j <= T.length){
        // 当当前所指的字符相等时，主串和子串以此匹配下一个字符
        if (S.ch[i] == T.ch[j]){
            ++i;
            ++j;
        }
        else{  // 进行回溯
            i = i - j + 2;
            j = 1;
        }     
    }
    // 当匹配成功了
    if (j >= T.length)
        return i - T.length;
    else  // 匹配不成功
        return 0;
       
}
 
// BF算法   从某一位置开始进行查找 pos
int IndexBF(SString S , SString T , int pos){
    int i = pos, j = 1;
    // 在有效范围内进行搜索
    while(i <= S.length && j <= T.length){
        // 当当前所指的字符相等时，主串和子串以此匹配下一个字符
        if (S.ch[i] == T.ch[j]){
            ++i;
            ++j;
        }
        else{  // 进行回溯
            i = i - j + 2;
            j = 1;
        }     
    }
    // 当匹配成功了
    if (j >= T.length)
        return i - T.length;
    else  // 匹配不成功
        return 0;
       
}

  
int main(){
  

    SString org , str ;

    int ans = IndexBF(org , str);
    cout << ans <<endl;
    
    system("pause");
    return 0;
}
