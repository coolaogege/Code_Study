#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// queue容器 头文件
#include<queue>


// queue容器 初始化  
// 格式为：explicit queue (const container_type& ctnr = container_type());
queue<int> q;         //创建一个空的没有数据的队列q
queue<int> qoo(q);    //创建一个队列其元素为q的全部内容


// 标准的队列创建方法是直接创建空队列再进行其他的操作，由于队列的特殊性质，拥有其他容器的参数可以这样创建
vector<int> v(3,100);           
queue<int,vector<int> > s(v);  //注意，> >符号之间需要有一个空格隔开



int main()
{

    // 栈和队列都属于一种特殊的数据结构
    // 只能通过访问顶层数据并不断剔除数据的方法进行全部访问，因此没有直接的迭代器。

    // 先通过queue<int> q创建了一个队列，命名为q
    queue<int> q;

    q.push(10);


    // 常用接口（常用的）

    // 获取大小size()   size_type size() const;
    cout<<q.size()<<endl;  // 直接返回队列元素的个数

   
    //  入队push()  void push (const value_type& val);
    q.push(100);    

    // 访问队头元素front()    const value_type& front() const;
    q.front()+=500;     //对队头元素进行修改
    cout<<q.front()<<endl;   //直接输出内容

    // 访问队尾元素back()   const value_type& back() const;
    q.push(50);
    q.back()+=100;     //对队尾元素进行修改
    cout<<q.back()<<endl;

    // 出队pop()   void pop();
    q.pop();

    // 判空empty()   bool empty() const;
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
      
   
    system("pause");
    return 0;
}

