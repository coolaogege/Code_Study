#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;


#define maxLen 255

// 串的顺序存储方式 数组
typedef struct 
{
    char ch[maxLen + 1];        // 存储串的一维数组
    int  length;                // 串的当前长度
}SString;


int Next[maxLen] = {0};


// 获取Next[]
void getNext(SString T , int &next){

}

// KMP算法   从某一位置开始进行查找 pos
int IndexKMP(SString S , SString T , int pos){
    int i = pos, j = 1;
    // 在有效范围内进行搜索
    while(i <= S.length && j <= T.length){
        // 当当前所指的字符相等时，主串和子串以此匹配下一个字符
        if (j == 0 || S.ch[i] == T.ch[j]){
            ++i;
            ++j;
        }
        else{  // 查找Next[j]表  
            // i不变  j后退
            j = Next[j];
        }     
    }
    // 当匹配成功了
    if (j >= T.length)
        return i - T.length;
    else  // 匹配不成功
        return 0;
       
}


// 创建Next[]  
int *buildNext(char *P){
    int m = strlen(P) , j=0;
    int * N = new int[m];
    int t = N[0] = -1;
    while( j < m-1 ){
        if( 0 > t || P[j] == P[t] ){
            N[++j] = ++t;
        }
        else{
            t = N[t];
        }
    }
    return N;
}

// KMP算法  
int KMP(char T[],char P[]){ //T--主串,P--模式串
    int *next = buildNext(P);   //构造NEXT表
    int n = strlen(T) , i=0;
    int m = strlen(P) , j=0;
    while( j<m && i<n ){
        if( j<0 || T[i]==P[j] ){
            i++;
            j++;
        }else{
            j = next[j];
        }
         
    }
    delete []next;
    return i-j;
}

int main(){
  
    char org[] = "ABABABABABD";
    char str[] = "ABABD";
    int ans = KMP(org,str);
    cout << ans <<endl;

    system("pause");
    return 0;
}