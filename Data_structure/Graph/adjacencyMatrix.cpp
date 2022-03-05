#include <iostream>
using namespace std;

#define MVNum 100       // 最大顶点数
#define MaxInt 32767    // 表示极大值 无穷

typedef char VerTexType;    // 设置顶点数据类型为字符型
typedef int ArcType;        // 设置边数据类型为整型


typedef struct {
    /* data */
    VerTexType vexs[MVNum];     // 顶点表
    ArcType arcs[MVNum][MVNum]; // 邻接矩阵
    int vexnum,arcnum;          // 图的当前点数和边数

}AMGraph;


// 查找 输入顶点在 邻接表中的下标
int LocateVex(AMGraph G , VerTexType u){
    int i;
    for ( i = 0; i < G.vexnum; i++){
        /* code */
        if (u == G.vexs[i]){
            /* code */
            return i ;
        }
     
    }
    return -1;
    
}

// 创建无向网
void CreatUND(AMGraph &G){
    VerTexType v1 , v2;
    ArcType w;

    // 输入 总顶点数  总边数
    cout << "vexnum and arcnum :  " << endl;
    cin>>G.vexnum>>G.arcnum;
    // 依次输入每个顶点的信息  ---> 顶点表
    cout << "Input data of vexs:  " << endl;
    for (int i = 0; i < G.vexnum; i++){
        /* code */
        cin >> G.vexs[i]; 
    }
    // 初始化 邻接矩阵
    for (int i = 0; i < G.vexnum; i++){
        for (int j = 0; j < G.vexnum; j++){
            /* code */
            G.arcs[i][j] = MaxInt;
        }            
    }
    // 构造邻接矩阵 输入边的情况
    cout << "Input two related vexs and weight :" << endl;
    for (int k = 0; k < G.arcnum; k++){
        /* code */
        // 当是无向图时  即 权值w = 1 ， 且 没关系的顶点的权值设置为0即可
        cin>>v1>>v2>>w;  // 输入一条边所依附的顶点及边的权值
        int i,j = 0;
        i = LocateVex(G , v1);  // 确定v1和v2在G中的位置
        j = LocateVex(G , v2);
        G.arcs[i][j] = G.arcs[j][i] = w;  // 当有向网时 ，注意后面的一句不要加
    }
    
}

// 遍历邻接矩阵
void Traversal(AMGraph G){
    cout << "adjacencyMatrix : " << endl;
    for (int i = 0; i < G.vexnum; i++){
        /* code */
        for (int j = 0; j < G.vexnum; j++){
            /* code */
            cout << G.arcs[i][j] << "  ";
        }
        cout << endl;
    }
    
}

int main(){
    // 创建一个图
    AMGraph Graph;
    // 创建无向网 UND
    CreatUND(Graph);
    // 遍历无向网
    Traversal(Graph);

    system("pause");
    return 0;

}
