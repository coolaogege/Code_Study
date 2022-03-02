// Note: 学到了  &  *  的使用
// Node p    Node *p   &p  *p   
// 声明一个节点p   Node p    &p  得到该节点p的地址(引用)      *p  得到该节点的内容值(值传递)  p.  这么使用
// 声明 一个指针 Node *p   p为指针类型 指向一个结点的地址  p-> 这么使用

// 另一个地方  free(temp);  -----  这句话出错！！！！
// 加上这句话 导致了 后序遍历的失败!

#include <iostream>

using namespace std;


//树的结点  /  栈的结点设计
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* next;
} Node;


//树根
typedef struct {
    Node* root;
} Tree;


//利用上面的结点创建栈，分为指向头结点的top指针和计数用的count
typedef struct stack    
{
    Node *top;
    int count;
} Link_Stack;




//创建栈
Link_Stack *Creat_stack()
{
    Link_Stack *p;
    //p = new Link_Stack;
    p=(Link_Stack*)malloc(sizeof(Link_Stack));
    if(p==NULL){
        printf("Failed to allocate memory space");  // 创建失败
        exit(0);
    }
    p->count = 0;
    p->top = NULL;
    return p;
}
 
//入栈 push
Link_Stack *Push_stack(Link_Stack *p, Node *elem)
{
    if (p == NULL)
        return NULL;
    Node *temp = elem; // 记录指针
    temp->next = p->top;
    p->top = temp;
    p->count++;
    return p;
}
 
//出栈 pop
Link_Stack *Pop_stack(Link_Stack *p, Node *elem)
{
    Node *temp;
    temp = p->top;
    if (p->top == NULL)
    {
        printf("Error: Stack is Null");  // 错误：栈为空
        return p;
    }
    else
    {
        *elem = *temp;  // 获取内容
        p->top = p->top->next;

        // free(temp);  -----  这句话出错！！！！

        //delete temp;
        p->count--;
        return p;
    }
}

//判断栈是否为空
bool StackEmpty(Link_Stack *p)
{
    Node *temp;
    temp = p->top;
    if (p->top == NULL)
        return true;
    else
        return false;
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

//树的中序遍历 
void inorder(Node* node){  //  Key!!!   传递指针！！！
    // 创建一个栈
    Link_Stack *S;
    S = Creat_stack();
    // 创建一个指针变量指向根节点地址
    Node* p = node;
    Node q;
    

    while (p || !StackEmpty(S)){
        if (p){
            Push_stack(S , p);
            p = p->left;
        }
        else{
            Pop_stack(S , &q);
            cout << q.data << "  " ;
            p = q.right;
        }
    }
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

  
int main(){
    Tree tree;
    tree.root = NULL;//创建一个空树
    int n;
    // scanf("%d",&n);
    cin>>n;
  
    //输入n个数并创建这个树
    for (int i = 0; i < n; i++){
        int temp;
        // scanf("%d",&temp);
        cin>>temp;
        insert(&tree, temp);
    }
  
    preorder(tree.root);   //前序遍历
    cout << endl;
    inorder(tree.root);        //中序遍历  
    cout << endl;
    postorder(tree.root);  //后序遍历
    cout << endl;

    system("pause"); 
    return 0;
}