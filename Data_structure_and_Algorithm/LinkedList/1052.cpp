// Date : 2022.2.17
// Descibe: [编程入门]链表合并
//          已有a、b两个链表，每个链表中的结点包括学号、成绩。要求把两个链表合并，按学号升序排列。
// author : YA 

// Note : 无

#include<bits/stdc++.h>
using namespace std;

//定义结点类型
typedef struct LNode {
    int id;
    int score;
    struct LNode *next;
} LNode,*PtrNode;

//SWAP函数
void swap(int *a,int *b) {
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

//创建
PtrNode creat_list(int n) {
    PtrNode L,p,q;
    L=(LNode *)malloc(sizeof(LNode));
    L->next=NULL;
    q=L;
    for(int i=0; i<n; i++) {
        p=(LNode *)malloc(sizeof(LNode));
        cin>>p->id>>p->score;
        p->next=NULL;
        q->next=p;
        q=p;
    }
    return L;
}

//打印
void print_list(PtrNode L) {
    LNode *p;
    p=L->next;
    while(p) {
        cout<<p->id<<' '<<p->score<<endl;
        p=p->next;
    }
}

//合并
PtrNode merge_list(PtrNode s1,PtrNode s2) {
    if(s1==NULL||s2==NULL)
        return NULL;
    PtrNode temp=s1;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    PtrNode foll=s2;
    temp->next=foll->next;
    free(foll);
    return s1;
}
 
//=============插入排序==================//
void insertSort(PtrNode mylist) {
    if((mylist -> next == NULL) || (mylist -> next -> next == NULL)) {
        return;
    }
    LNode * head, * p1, * prep1, * p2, * prep2, * temp;
    head = mylist;
    prep1 = head -> next;
    p1 = prep1 -> next;
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
 
int main() {
    PtrNode L1,L2,L;
    int n,m;
    cin>>n>>m;
    L1=creat_list(n);
    L2=creat_list(m);
    L=merge_list(L1,L2);
    insertSort(L);

    cout<< "\n" << "---------"<< endl;

    print_list(L);

    system("pause");
    return 0;
}
