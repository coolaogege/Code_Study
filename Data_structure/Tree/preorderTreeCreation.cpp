// Note:

//        NULL

#include <iostream>

using namespace std;


//树的结点  /  栈的结点  / 队列节点
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


//树根
typedef struct {
    Node* root;
} Tree;

 
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
void push(queue *q , Node *elem){
    Node *n = elem;
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
void pop(queue *q , Node *elem){
    Node *n=q->front;

    *elem = *n;

    if(empty(q)){
        return ;    //此时队列为空，直接返回函数结束
    }
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
 

//创建树--插入数据
void insert(Tree* tree, int value){
    //创建一个节点，让左右指针全部指向空，数据为value
    Node* node=(Node*)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
  
    //判断树是不是空树，如果是，直接让树根指向这一个结点即可
    if (tree->root == NULL){
        tree->root = node;
    } 
    else {//不是空树
        Node* temp = tree->root;//从树根开始
        while (temp != NULL){
            if (value < temp->data){ //小于就进左儿子
                if (temp->left == NULL){
                    temp->left = node;
                    return;
                } 
                else {//继续往下搜寻
                    temp = temp->left;
                }
            } 
            else { //否则进右儿子
                if (temp->right == NULL){
                    temp->right = node;
                    return;
                }
                else {//继续往下搜寻
                    temp = temp->right;
                }
            }
        }
    }
    return;
}


//创建树 -- 先序创建树
void preInsert(Node &T){

    int ch;
    cin>>ch;

    if (ch == 9){
        T.data = 0;
        T.left = NULL;
        T.right = NULL;
        T.next = NULL;
    }
    else{
        Node T;
        T.data = ch;  // 生成根节点
        preInsert(*T.left);  // 构造左子树
        preInsert(*T.right); // 构造右子树
    }

    return;
}

//树的先序遍历 Preorder traversal
void preorder(Node* node){
    if (node != NULL)
    {
        // printf("%d ",node->data);
        cout << node->data << "  " ;
        preorder(node->left);
        preorder(node->right);
    }
}

//树的层次遍历 
void levelOrder(Node* node){ 

    // 创建一个节点
    Node p;

    // 初始化队列
    queue *qu=init_queue();

    // 根节点指针进入队列
    push(qu , node);

    while ( !empty(qu) ){  // 队列不为空时 ， 则循环
        pop(qu , &p);
        cout << p.data << "  " ;
        if (p.left != NULL)
            push(qu , p.left);  // 有左子树  进队
        if (p.right != NULL)
            push(qu , p.right); // 有右子树  进队
    }
}


//树的后序遍历 Post-order traversal
void postorder(Node* node){
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        // printf("%d ",node->data);
        cout << node->data << "  " ;
    }
}
 
//主函数调用，这里只是简单介绍用法
int main(){
    Tree tree;
    tree.root = NULL;//创建一个空树

    cout << &tree << endl;
    cout << tree.root << endl;

    // 目前还存在一定的问题！！！  主要是 传递的指针和值  不会用！

    // 1 2 3 9 9 4 5 9 6 9 9 7 9 9 9 
    // preInsert(tree.root);  //先序生成树 

    preorder(tree.root);   //前序遍历
    cout << endl;


    system("pause"); 
    return 0;
}