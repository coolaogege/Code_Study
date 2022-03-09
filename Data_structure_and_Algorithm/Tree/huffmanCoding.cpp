// Note: 
// 哈夫曼编码的实现 
// 哈夫曼树（最优二叉树） ----> 带权路径长度最短的树  WPL
// 利用数组（顺序表形式） ----> 0元素不会被使用！！

#include<iostream>
using namespace std;

// 构造哈夫曼树节点
typedef struct 
{
    /* data */
    int weight;                     // 结点权值   
    int parent , lchild , rchild;   // 结点的双亲 、 左孩子 、 右孩子
} HTNode , *HuffumanTree;

// 构造哈夫曼树  n个结点 分别对应其权值
// Step1：申请空间进行初始化各变量   2n个结点空间  0号不适用
// Step2：创建树，循环次数为n-1次   
void CreatHuffmanTree(HuffumanTree &HT , int n)
{
    // Step1 初始化
    if(n <= 1) return;
    // 创建一个变量  0号未使用！ 用来表示 1-m 个结点 
    int m = 2*n - 1;
    HT = new HTNode[m + 1];  // 声明2n个结点空间
    // 各结点进行初始化
    for (int i = 1; i <= m; i++)
    {
        /* code */
        HT[i].parent = HT[i].lchild = HT[i].rchild = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        /* code */
        cin>>HT[i].weight; // 给每个结点 赋权值
    }
    
    // Step2 创建哈夫曼树
    // 首先明确循环的次数 n-1次
    for (int i = n+1; i <= m; i++)
    {
        // 通过 n-1 次的选择、删除、合并来创建哈夫曼树 
        Select(HT , i-1 , S1 , S2);
        // 在HT[k]（1 <= k <= i-1）中选择两个其双亲域为0且权值最小的结点，返回他们在HT中的序号S1和S2
        HT[S1].parent = HT[S2].parent = i;
        // 得到新结点i，然后从森林中删除S1,S2。将其双亲改成i。将结点i的左右孩子改成S1,S2。
        HT[i].lchild = HT[S1]; 
        HT[i].rchild = HT[S2]; 
        HT[i].weight = HT[S1].weight + HT[S2].weight;  // 计算结点i的权值
    }
    // 最后循环结束，只有一个结点的父节点为0，即最后一个结点
}


