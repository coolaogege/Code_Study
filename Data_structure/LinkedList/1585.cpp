// Date : 2022.2.17
// Descibe: 读入10个复数，建立对应链表，然后求所有复数的和。
// author : YA

// Note : 无

#include <bits/stdc++.h> // 这是一个包含了C++所有头文件的一个头文件，为了方便而发明的
using namespace std;

//定义结点类型
typedef struct Node {
    int plural;  //定义复数
    int real_number; // 定义实数
    struct Node *next;  //单链表的指针域  -- 下一节点的指针
} Node,*LinkedList;  //Node表示结点的类型，LinkedList表示指向Node结点类型的指针类型 

// 建立链表
LinkedList BuildList()
{
    // LinkedList new_node,L,p;

    int real_number;
    int plural;
    int n = 1;

    LinkedList L,p,q;
    L=(Node *)malloc(sizeof(Node));
    L->next=NULL;
    q=L;
    for(int i=0; i<n; i++) {
        p=(Node *)malloc(sizeof(Node));
        cin>>real_number>>plural;
        p->real_number = real_number;
        p->plural = plural;

        p->next=NULL;
        q->next=p;
        q=p;
    }    

    // 读入数据
    // while (n--)
    // {
    //     cin >> real_number;
    //     cin >> plural;
    //     new_node = (Node *)malloc(sizeof(Node)); // 请求空间
    //     if (new_node == NULL) // 申请空间失败
    //     {
    //         cout << "failed" << endl;
    //         break; //跳出while循环
    //     }
    //     new_node->real_number = real_number;  //新节点数据获取
    //     new_node->plural = plural;


    //     L->next = new_node;
    //     new_node->next = NULL;
    //     L = new_node;

    // }
    return L;
}

// 遍历 获取 复数运算结果进行显示结果
void Print(LinkedList L)
{
    LinkedList p;
    p = L;
    int real_number = 0;
    int plural = 0;
    while (p)
    {
        real_number += p->real_number;
        plural += p->plural;
        p = p->next;
    }
    cout << real_number << "+" << plural << "i" << endl;
}

//打印
void print_list(LinkedList L) {
    Node *p;
    p=L->next;
    while(p) { // 判断是否为NULL  -- 即是否遍历完当前链表的最后一个元素！
        cout<<p->real_number<<' '<<p->real_number<<endl;
        p=p->next;
    }
}

int main()
{
    LinkedList L = BuildList();
    cout <<  "\n" <<  "-------------" << endl;
    print_list(L);

    cout <<  "\n" <<  "-------------" << endl;

    Print(L);
    system("pause");
    return 0;
}