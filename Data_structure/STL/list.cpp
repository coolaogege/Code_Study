#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// list容器 头文件
#include <list>


// list容器 初始化  
// 格式为：explicit list (const allocator_type& alloc = allocator_type());
list<int> l1;           //创建一个空链表
list<int> l2(10);       //创建一个链表其有10个空元素
list<int> l3(5,20);     //创建一个链表其有5个元素内容为20
list<int> l4(l3.begin(),l3.end());  //创建一个链表其内容为l3的内容
list<int> l5(l4);               //创建一个链表其内容为l4的内容



// 简单的自定义降序序列
int cmp(const int &a,const int &b){ 
    return a>b;
}


int main()
{

    list<int> li(5,20);        //创建一个链表li

    // 遍历 
    for(list<int>::iterator it=li.begin();it!=li.end();it++){
            cout<<*it<<' ';
        }
    cout<<endl;

    // 常用接口（常用的）
    
    // 判断是否为空empty()   bool empty() const;
    if(li.empty()){     //当链表为空的时候执行
        cout<<"is empty()"<<endl;
    }
    else{
        cout<<"not empty()"<<endl;
    }

    // 获取大小size()   size_type size() const;
    cout<<li.size()<<endl;

    // 链表前插入push_front() &&删除 pop_front()   
    // push_front()表示在链表最前端插入一个数据 void push_front (const value_type& val);
    // pop_front()表示在链表最前端删除一个数据  void pop_front();
    li.push_front(10);
    li.pop_front();
    
    // 链表后插入push_back() &&删除 pop_back()
    // push_back()表示在链表尾插入一个数据，pop_back()表示将链表尾删除一个数据。
    // void push_back (const value_type& val);
    // void pop_back(); 
    li.push_back(10);
    li.pop_back();

    // 插入insert()
    // 插入单一数据到指定位置： iterator insert (iterator position, const value_type& val);
    // 插入一段数据到指定位置： void insert (iterator position, size_type n, const value_type& val);
    // 插入一段别的容器的数据到指定位置： void insert (iterator position, InputIterator first, InputIterator last);
    li.insert(li.begin(),10);     //在链表最前端插入数据10
    li.insert(li.begin(),5,20);   //在链表最前端插入5个数据内容为20
  
    list<int> k(2,50);   //创建一个新的链表k,其拥有2个元素内容均为50
    li.insert(li.begin(),k.begin(),k.end());  //在链表v最前端插入链表上K的全部内容
    
    // 删除erase()   iterator erase (iterator position);     iterator erase (iterator first, iterator last);
    li.erase(li.begin());     //删除第一个元素
    
    // li.erase(li.begin(),li.begin() + 4); //删除前4个元素   ------  出现错误  不能 +4  vector可以

    // 排序sort()
    // 让整个链表变成升序状态，或者变成自定义的排序状态
    // void sort();
    // template <class Compare>   void sort (Compare comp);
    list<int> li2(li);
    li2.sort(cmp);
    for(list<int>::iterator it=li2.begin();it!=li2.end();it++){
        cout<<*it<<' ';
    }
    cout<<endl;

    // 逆序reverse()  void reverse();
    li.reverse();
    for(list<int>::iterator it=li.begin();it!=li.end();it++){
        cout<<*it<<' ';
    }
    cout<<endl;

    // 清空clear()    void clear();
    li.clear();      //清空向量
    for(list<int>::iterator it=li.begin();it!=li.end();it++){
        cout<<*it<<' ';
    }
    cout<<endl;    
   
    system("pause");
    return 0;
}

