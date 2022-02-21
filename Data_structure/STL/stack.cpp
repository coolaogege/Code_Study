#include <bits/stdc++.h>
#include <iostream>

using namespace std;


#include<vector>
// stack容器 头文件
#include<stack>


// stack容器 初始化  
// 格式为：explicit stack (const container_type& ctnr = container_type());
stack<int> a;
stack<int> v(a);


// 标准的栈创建方法是直接创建空栈，由于栈的特殊性质，让他拥有其他容器的参数可以这样创建
vector<int> v1(3,100);           
// stack< int, vector<int> > a(v1);  //注意，> >符号之间需要有一个空格隔开    -----  注意在这里会出现错误！



int main()
{

    // 栈和队列都属于一种特殊的数据结构
    // 只能通过访问顶层数据并不断剔除数据的方法进行全部访问，因此没有直接的迭代器。

    // stack<int> s 预先创建了一个栈，命名为s
    stack<int> s;

    s.push(10);


    // 常用接口（常用的）

    // 获取大小size()   size_type size() const;
    cout<<s.size()<<endl;

    // 返回栈顶元素top()    const_reference& top() const;  

    cout<<s.top()<<endl;     //直接返回输出即可
    s.top()+=100;            //也可以直接对栈定元素进行修改操作 
    
    // 入栈push()  void push (const value_type& val);
    s.push(10);
    s.push(20);

    // 出栈pop()   void pop();
    s.pop();

    // 判空empty()   bool empty() const;
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
      
   
    system("pause");
    return 0;
}

