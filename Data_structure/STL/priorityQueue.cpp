// 优先队列是一种极其特殊的队列     优先队列的底层是以散列的状态（非线性）表现的
// 优先队列并不遵从标准的先进先出，而是对每一个数据赋予一个权值
// 根据当前队列权值的状态进行排序，使得权值最大（或最小）的永远排在队列的最前面

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// 其属于队列的一种 可以直接使用队列的头文件#include<queue>
// queue容器 头文件
#include<queue>


// priority_queue容器 初始化    ----- 不一样的地方

// T就是Type为数据类型
// Container是容器类型，（Container必须是用数组实现的容器，比如vector,deque等等，但不能用 list。STL里面默认用的是vector）
// Compare是比较方法，类似于sort第三个参数那样的比较方式，对于自定义类型，需要我们手动进行比较运算符的重载--结构体的运算符重载完成

// priority_queue<T, Container, Compare>    
// priority_queue<T>        //直接输入元素则使用默认容器和比较函数
struct cmp
{ //这个比较要用结构体表示
    bool operator()(int &a, int &b) const
    {
        return a > b;
    }
};
  
priority_queue<int,vector<int>,cmp> q;    //使用自定义比较方法
priority_queue<int> pq;



int main()
{

    // 栈和队列都属于一种特殊的数据结构
    // 只能通过访问顶层数据并不断剔除数据的方法进行全部访问，因此没有直接的迭代器。

    // 先通过queue<int> q创建了一个队列，命名为q
    priority_queue <int> q;

    q.push(10);


    // 常用接口（常用的）

    // 获取大小size()   size_type size() const;
    cout<<q.size()<<endl;  // 直接返回队列元素的个数

   
    //  入队push()  void push (const value_type& val);
    q.push(100);    

    // top()    const value_type& top() const;
    cout<<q.top()<<endl;   //直接输出内容

    // 出队pop()   void pop();
    q.pop();

    // 判空empty()   bool empty() const;
    while(!q.empty()){
        cout<<q.top()<<endl;
        q.pop();
    }


    priority_queue<int, vector<int>, cmp> qq;
    for (int i = 1; i <= 5; i++)
    {
        qq.push(i * 10);
        cout << "push element " << i << endl;
    }
    qq.push(15);
    qq.push(4);
    int i = 1;
    while (!qq.empty())
    {
        int temp = qq.top();
        qq.pop();
        cout << "No " << i++ << " element is: " << temp << endl;
    }  
   
    system("pause");
    return 0;
}

