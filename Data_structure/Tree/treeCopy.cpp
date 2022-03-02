#include <iostream>

using namespace std;


// 二叉树的二叉链表存储表示
typedef struct BiTNode{
    int data;
    struct BiTNode* left;
    struct BiTNode* right;
} BiTNode , *BiTree;

// 先序生成树
void CreateBiTree(BiTree &T){
    int ch;
    cin>>ch;
    if (ch == 9)
        T = NULL;
    else{
        T = new BiTNode; // 生成根节点
        T->data = ch;  
        CreateBiTree(T->left);  // 构造左子树
        CreateBiTree(T->right); // 构造右子树
    }
}

//树的先序遍历 Preorder traversal
void preorder(BiTree T){
    if (T){
        cout << T->data << "  " ;
        preorder(T->left);
        preorder(T->right);
    }
}

// 复制二叉树
void Copy(BiTree T , BiTree &NewT){

    if (T == NULL){  // 如果是空树  结束
        NewT = NULL;
        return;
    }
    else{
        NewT = new BiTNode;  // 建立新节点 
        NewT->data = T->data;  // 复制数据
        Copy(T->left , NewT->left);    // 递归复制左子树
        Copy(T->right , NewT->right);  // 递归复制右子树
    }
}


//主函数调用，这里只是简单介绍用法
int main(){
    BiTree tree; // 创建一个树

    // 1 2 3 9 9 4 5 9 6 9 9 7 9 9 9 
    CreateBiTree(tree); //先序生成树 

    preorder(tree);    //前序遍历
    cout << endl;

    BiTree Newtree;   // 创建一个新树

    Copy(tree , Newtree); // 复制
    preorder(Newtree);    //前序遍历
    cout << endl;

    system("pause"); 
    return 0;
}