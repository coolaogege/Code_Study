// Date : 2022.2.17
// Descibe: 单链表初始化 建立 遍历 增删
// author : YA 

// Note : 因为目前还不会获取如何输入数据 ， 因此采用固定方式 ， 头插法无法使用！

#include <stdio.h>
#include <stdlib.h>
 
//定义结点类型
typedef struct Node {
    int data;           //数据类型，你可以把int型的data换成任意数据类型，包括结构体struct等复合类型
    struct Node *next;          //单链表的指针域
} Node,*LinkedList;
 
//单链表的初始化
LinkedList LinkedListInit() {
    Node *L;
    L = (Node *)malloc(sizeof(Node));   //申请结点空间
    if(L==NULL){    //判断申请空间是否失败
        exit(0);    //如果失败则退出程序
    }
    L->next = NULL;          //将next设置为NULL,初始长度为0的单链表
    return L;
}
 
 
//单链表的建立1，头插法建立单链表
LinkedList LinkedListCreatH() {
    Node *L;
    L = (Node *)malloc(sizeof(Node));   //申请头结点空间
    L->next = NULL;                      //初始化一个空链表
 
    int x[6] = {1,2,3,4,5,6};                         //x为链表数据域中的数据
    int i = 0;

    while(i<6) {
        Node *p;
        p = (Node *)malloc(sizeof(Node));   //申请新的结点
        p->data = x[i];                     //结点数据域赋值
        p->next = L->next;                    //将结点插入到表头L-->|2|-->|1|-->NULL
        L->next = p;

        i++;
    }
    return L;
}
 
 
//单链表的建立2，尾插法建立单链表
 
LinkedList LinkedListCreatT() {
    Node *L;
    L = (Node *)malloc(sizeof(Node));   //申请头结点空间
    L->next = NULL;                  //初始化一个空链表
    Node *r;
    r = L;                          //r始终指向终端结点，开始时指向头结点

    int x[6] = {1,3,4,5,6,7};                         //x为链表数据域中的数据
    int i = 0;

    while(i<6) {
        Node *p;
        p = (Node *)malloc(sizeof(Node));   //申请新的结点
        p->data = x[i];                     //结点数据域赋值
        r->next = p;                 //将结点插入到表头L-->|1|-->|2|-->NULL
        r = p;

        i++;
    }
    r->next = NULL;
 
    return L;
}
 
 
//单链表的插入，在链表的第i个位置插入x的元素
 
LinkedList LinkedListInsert(LinkedList L,int i,int x) {
    Node *pre;                      //pre为前驱结点
    // 相当于是索引到 第i个位置的节点
    pre = L;
    int tempi = 0;
    for (tempi = 1; tempi < i; tempi++) {
        pre = pre->next;                 //查找第i个位置的前驱结点
    }
    // 创建新节点 请求空间 建立新链！
    Node *p;                                //插入的结点为p
    p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = pre->next;
    pre->next = p;
 
    return L;
}
 
 
//单链表的删除，在链表中删除值为x的元素
// 用两个手指 来演示 当前和前驱节点  
LinkedList LinkedListDelete(LinkedList L,int x) {
    Node *p,*pre;                   //pre为前驱结点，p为查找的结点。
    p = L->next;
     
    while(p->data != x) {              //查找值为x的元素
        pre = p;
        p = p->next;
    }
    pre->next = p->next;          //删除操作，将其前驱next指向其后继。
    free(p);    // 将原有的结点通过free函数释放掉
     
    return L;
}
 
//链表内容的修改，再链表中修改值为x的元素变为为k。
//相当于是遍历的方式！
LinkedList LinkedListReplace(LinkedList L,int x,int k) {
    Node *p=L->next;
    int i=0;
    while(p){
        if(p->data==x){
            p->data=k;
        }
        p=p->next;
    }
    return L;
}
 
 
//遍历输出单链表
void printList(LinkedList L){
    Node *p=L->next;
    int i=0;
    while(p){
        printf("the %d value : %d\n",++i,p->data); // "第%d个元素的值为:
        p=p->next;
    }
} 
 
/* int main() {
    //创建 
    LinkedList list;
    printf("input data of linkedlist: \n");  // 请输入单链表的数据：
    list = LinkedListCreatT();
    //list=LinkedListCreatT();
    printList(list);
     
    //插入 
    int i;
    int x;
    printf("Please enter the location to insert the data : ");  // 请输入插入数据的位置
    scanf("%d",&i);
    printf("Please enter a value for the inserted data : ");  // 请输入插入数据的值
    scanf("%d",&x);
    LinkedListInsert(list,i,x);
    printList(list);
     
    //修改
    printf("Please enter the modified data : "); // 请输入修改的数据
    scanf("%d",&i);
    printf("Please enter the modified data : "); // 请输入修改的数据
    scanf("%d",&x);
    LinkedListReplace(list,i,x);
    printList(list);
     
    //删除 
    printf("Please enter the value of the element to remove : ");  // 请输入要删除的元素的值
    scanf("%d",&x);
    LinkedListDelete(list,x);
    printList(list);
 
    return 0;
} */

int main() {
    //创建 
    LinkedList list;
    printf("Data of linkedlist: \n");
    // list = LinkedListCreatH();
    list=LinkedListCreatT();
    printList(list);
    
	printf("----------------------\n");
	
	LinkedListReplace(list,1,2);    
	
	printList(list);
	
	printf("----------------------\n");
	
	LinkedListInsert(list,1,1);
    printList(list);
	
	printf("----------------------\n");
	
	LinkedListDelete(list,7);
    printList(list);
 
    system("pause");
    return 0;
}