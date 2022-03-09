#include <iostream>
using namespace std;

#define MVNum 100       // 最大顶点数
#define MaxInt 32767    // 表示极大值 无穷

typedef char VerTexType;    // 设置顶点数据类型为字符型
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
        ArcNode p1;
        // 邻接点的序号
        p1.adjvex = j; 
        // 头插法
        p1.nextarc = G.vertices[i].firstarc;  
        G.vertices[i].firstarc = &p1;

        // 无向的，因此需要给另一个也要插入结点   同样的操作 

        // 建立边结点
        ArcNode p2;
        // 邻接点的序号
        p2.adjvex = i; 
        // 头插法
        p2.nextarc = G.vertices[j].firstarc;  
        G.vertices[j].firstarc = &p2;        
    }
    
}


int main(){ 
    // 创建一个图
    ALGraph Graph;
    // 创建无向网 UND
    CreatUND(Graph);

    system("pause");
    return 0;

}
