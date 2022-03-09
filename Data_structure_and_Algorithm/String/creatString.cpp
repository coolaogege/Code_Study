#include <iostream>
using namespace std;


#define maxLen 255

// 串的顺序存储方式 数组
typedef struct 
{
    char ch[maxLen + 1];        // 存储串的一维数组
    int  length;                // 串的当前长度
}SString;


// 串的链式存储结构 块链结构
#define CHUNKSIZE 80 //块的大小可由用户定义

// 块结点
typedef struct Chunk
{
    /* data */
    char ch[CHUNKSIZE];
    struct Chunk * next;
}Chunk;

// 串的链式存储结构 块链结构
typedef struct 
{
    /* data */
    Chunk *head , *tail;        // 串的头指针和尾指针
    int curlen;                 // 串的当前长度
}LString;                       // 字符串的块链结构
 



