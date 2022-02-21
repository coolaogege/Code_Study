// Date : 2022.2.17
// Descibe: [编程入门]链表合并
//          已有a、b两个链表，每个链表中的结点包括学号、成绩。要求把两个链表合并，按学号升序排列。
// author : YA 

// Note : 无


#include<bits/stdc++.h>  // 这是一个包含了C++所有头文件的一个头文件，为了方便而发明的
using namespace std;

//定义结点类型
typedef struct Node {
    int id;  //定义ID
    int score; // 定义分数
    struct Node *next;  //单链表的指针域  -- 下一节点的指针
} Node,*LinkedList;  //Node表示结点的类型，LinkedList表示指向Node结点类型的指针类型 

//SWAP函数
void swap(int *a,int *b) {
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

//创建
LinkedList creat_list(int n) {
    LinkedList L,p,q;  // 创建节点  或者用 Node *L  一样的含义
    L=(Node *)malloc(sizeof(Node)); // 请求空间
    L->next=NULL; // 将next设置为NULL,初始长度为0的单链表
    q=L; // q是前驱节点
    // 向链表中加入节点
    for(int i=0; i<n; i++) {
        // 创建一个节点 加入对应信息 头插法 
        p=(Node *)malloc(sizeof(Node));
        cin>>p->id>>p->score; //获取终端输入的信息
        p->next=NULL;
        q->next=p;
        q=p;
    }
    return L; // 返回链表
}

//打印
void print_list(LinkedList L) {
    Node *p;
    p=L->next;
    while(p) { // 判断是否为NULL  -- 即是否遍历完当前链表的最后一个元素！
        cout<<p->id<<' '<<p->score<<endl;
        p=p->next;
    }
}

//合并
LinkedList merge_list(LinkedList s1,LinkedList s2) {
    if(s1==NULL && s2==NULL) // 判断链表是否都为空 
        return NULL;
    LinkedList temp=s1; // 链表1头节点  指针
    while(temp->next!=NULL) {  // 进行 等效中间链表
        temp=temp->next;
    }
    LinkedList foll=s2;  // 链表2头节点 指针
    temp->next=foll->next; // 只需要将链表1 和 链表2 接起来  指针连接  相当于是接起来
    free(foll);  // 将原有的结点通过free函数释放掉
    return s1;
}
 
//=============插入排序==================//
void insertSort(LinkedList mylist) {
    if((mylist -> next == NULL) || (mylist -> next -> next == NULL)) {  // 如果链表 为空 或者只有一个元素  直接返回
        return;
    }
    LinkedList head, p1, prep1, p2, prep2, temp;
    head = mylist; // 记录此链表
    prep1 = head -> next; // 第一个节点
    p1 = prep1 -> next; // 第二个节点
    //prep1和p1是否需要手动后移
    bool flag;
 
    while(p1 != NULL) {
        flag = true;
        temp = p1;
        //由于是单向链表，所以只能从头部开始检索
        for(prep2 = head, p2 = prep2 -> next; p2 != p1; prep2 = prep2 -> next, p2 = p2 -> next) {
            if(p2 -> id > p1 -> id) {
                p1 = p1 -> next;
                prep1 -> next = p1;
                prep2 -> next = temp;
                temp -> next = p2;
                flag = false;
                break;
            }
        }
        //手动后移prep1和p1
        if(flag) {
            prep1 = prep1 -> next;
            p1 = p1 -> next;
        }
    }
}

//=============冒泡排序==================//
// 可以看到要交换节点，我们需要：

// 随时记录pre,cur的前驱
// 两个临时变量保存pre,cur的后继
// 更改指针

// 比较麻烦 若只需要交换值 可以采用下面的程序  第一个是我的交换节点尝试 失败了!

// void MaoPao( LinkedList mylist)
// {
//     LinkedList p, q, temp;
//     p = mylist->next;
//     for(p;p->next!=NULL;p=p->next)
//     {
//         for(q=p->next;q!=NULL;q=q->next)
//         {
//             if(p->score > q->score)
//                 {
//                     p->next = q->next;
//                     q->next = p;
//                 }
//         }
//     }
// }


// void MaoPao( Node * head)
// {
//      Node * p, *q, *tail;

//     tail = NULL;

//     while ((head->next->next) != tail)
//     {
//         p = head;
//         q = head->next;
//         while (q->next != tail)
//         {
//             if ((q->score) > (q->next->score))
//             {
//                 p->next = q->next;
//                 q->next = q->next->next;
//                 p->next->next = q;
//                 q = p->next;
//             }
//             q = q->next;
//             p = p->next;
//         }
//         tail = q;
//     }
// }

int main() {
    LinkedList L1,L2,L;
    int n,m;
    cin>>n>>m;
    L1=creat_list(n);
    L2=creat_list(m);

    cout<< "\n" << "---------"<< endl;
    print_list(L1);

    cout<< "\n" << "---------"<< endl;
    print_list(L2);

    L=merge_list(L1,L2);

    cout<< "\n" << "---------"<< endl;
    print_list(L);

    insertSort(L);
    // MaoPao(L);

    cout<< "\n" << "---------"<< endl;
    print_list(L);

    cout<< "\n" << "---------"<< endl;

    LinkedList p;
    p = L;
    cout << p->next->id << endl; // 输出 2 

    system("pause");
    return 0;
}
