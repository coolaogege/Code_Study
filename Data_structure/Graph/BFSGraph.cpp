#include <iostream>
using namespace std;

#define MVNum 100       // 最大顶点数
#define MaxInt 32767    // 表示极大值 无穷

typedef int VerTexType;    // 设置顶点数据类型为字符型
typedef int OtherInfo;      // 设置边数据类型为整型

// 边结点结构
typedef struct ArcNode{
    int adjvex;          // 该边所指向的顶点的位置
    OtherInfo info;      // 和边相关的信息
    struct ArcNode * nextarc;   // 指向下一条边的结点地址的指针

}ArcNode; 

// 顶点的节点结构
typedef struct VNode{
    VerTexType data;     // 顶点信息
    ArcNode * firstarc;  // 指向第一条依附该顶点的边的指针

}VNode , AdjList[MVNum]; // AdjList表示邻接表类型 ---> AdjLit v;

// 图的结构的定义
typedef struct {
    AdjList vertices;           // vertices 是 vertex 的复数
    int vexnum,arcnum;          // 图的当前顶点数和弧数

}ALGraph;


int visted[MVNum] = {0};         // 记录该点是否被访问过



// 队列节点
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* next;
} Node;

//队列定义，队首指针和队尾指针
typedef struct {
    node *front;
    node *rear;
}queue;

//初始化结点
node *init_node(){
    node *n=(node*)malloc(sizeof(node));
    if(n==NULL){    //建立失败，退出
        exit(0);
    }
    return n;
}
 
//初始化队列
queue *init_queue(){
    queue *q=(queue*)malloc(sizeof(queue));
    if(q==NULL){    //建立失败，退出
        exit(0);
    }
    //头尾结点均赋值NULL
    q->front=NULL;  
    q->rear=NULL;
    return q;
}
 
//队列判空
bool empty(queue *q){
    if(q->front==NULL){
        return true;    //1--表示真，说明队列非空
    }
    else{
        return false;   //0--表示假，说明队列为空
    }
}
 
//入队操作
void push(queue *q , int data){
    node *n =init_node();
    n->data=data;
    n->next=NULL;   //采用尾插入法
    //if(q->rear==NULL){  
    if(empty(q)){
        q->front=n;
        q->rear=n;
    }else{
        q->rear->next=n;    //n成为当前尾结点的下一结点
        q->rear=n;  //让尾指针指向n
    }
}
 
//出队操作
void pop(queue *q , int *data){
    node *n=q->front;
    if(empty(q)){
        return ;    //此时队列为空，直接返回函数结束
    }

    *data = n->data ; 

    if(q->front==q->rear){
        q->front=NULL;  //只有一个元素时直接将两端指向制空即可
        q->rear=NULL;
        // free(n);        //记得归还内存空间
    }
    else{
        q->front=q->front->next;
        // free(n);
    }
}



// 查找 输入顶点在 邻接表中的下标
int LocateVex(ALGraph G , VerTexType u){
    int i;
    for ( i = 0; i < G.vexnum; i++){
        /* code */
        if (u == G.vertices[i].data){
            /* code */
            return i ;
        }
     
    }
    return -1;
    
}

// 创建无向网
void CreatUND(ALGraph &G){
    VerTexType v1 , v2;
    OtherInfo w;

    // 输入 总顶点数  总边数
    cout << "vexnum and arcnum :  " << endl;
    cin>>G.vexnum>>G.arcnum;

    // 依次输入每个顶点的信息  ---> 顶点表
    cout << "Input data of vexs:  " << endl;
    for (int i = 0; i < G.vexnum; i++){
        cin >> G.vertices[i].data; 
        // 初始化 邻接表各头结点的指针 firstarc 置空
        G.vertices[i].firstarc = NULL;
    }

    // 构造单链表 输入边的情况
    cout << "Input two related vexs and weight :" << endl;
    for (int k = 0; k < G.arcnum; k++){
        // 输入一条边所依附的顶点及边的权值
        cin>>v1>>v2>>w;  
        // 确定v1和v2在G中的位置
        int i,j = 0;
        i = LocateVex(G , v1);  
        j = LocateVex(G , v2);
        // 建立边结点

        // ArcNode *p2;   ----> 出错的地方！！ 第二次指针还是这个地址！  应该新开辟一个结点！ 正确的方式如下
        // ArcNode *p1=(ArcNode*)malloc(sizeof(ArcNode));
        ArcNode *p1 = new ArcNode;

        // 邻接点的序号
        p1->adjvex = j; 
        // 头插法
        p1->nextarc = G.vertices[i].firstarc;  
        G.vertices[i].firstarc = p1;

        // 无向的，因此需要给另一个也要插入结点   同样的操作 

        // 建立边结点
        // ArcNode *p2;
        ArcNode *p2 = new ArcNode;

        // 邻接点的序号
        p2->adjvex = i; 
        // 头插法
        p2->nextarc = G.vertices[j].firstarc;  
        G.vertices[j].firstarc = p2;        
    }
    
}

// 广度优先遍历 无向连通图
// 非递归的形式，使用队列，类似于 树的层次遍历
// G 邻接表类型的图  v 起始顶点
void BFSGraphUND(ALGraph G , int v){
    // 访问第v个顶点
    cout << v << endl; 
    visted[v-1] = 1;  // 将此节点 访问状态置为1

    // 创建辅助队列Q 进行初始化
    queue *Q=init_queue();
    // 节点进入队列
    push(Q , v);

    int u;

    // 当队列不为空时
    while( !empty(Q) ){
        // 队头元素出队 并置为u  
        pop(Q , &u);
        // 遍历此结点的所有边结点 ---> 即对每一条单链表进行遍历
        ArcNode * p = G.vertices[u-1].firstarc;
        while (p != NULL){
            if (!visted[p->adjvex]){ // 如果未被访问过
            // 输出结点，并且访问状态置为1
                cout << p->adjvex + 1 << endl;   
                visted[p->adjvex] = 1;
            }
            v = p->adjvex + 1;
            p = p->nextarc;          
        }
        // 节点进入队列
        push(Q , v);  
    }
     
} 

/* 
8 9

1 2 3 4 5 6 7 8

1 2 1 
1 3 1
2 4 1
2 5 1
3 6 1
3 7 1
4 8 1
5 8 1 
6 7 1
*/


int main(){ 
    // 创建一个图
    ALGraph Graph;
    // 创建无向网 UND
    CreatUND(Graph);
    // 广度优先遍历无向图 ----> 起始结点设为1
    BFSGraphUND(Graph , 1);


    system("pause");
    return 0;

}
