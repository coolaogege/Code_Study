#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// vector容器 头文件
#include <vector>


// vector容器 初始化  
// 格式为：vector<Data_Types> name;
vector<int> v1;          //创建一个空的向量v1
vector<int> v2(10);      //创建一个向量v2，其已开辟10个元素的空间，相当于int v[10];
vector<int> v3(10,5);    //创建一个向量v3，其已开辟10个元素的空间并全部赋值为5
vector<int> v4(v3.begin(),v3.end());    //创建一个向量v3,其内容为向量v4的内容
vector<int> v5(v4);      //创建一个向量v5，其包含了v4的全部内容




int main()
{

    // 迭代器
    vector<int> v(10,5);        //创建一个向量v
    vector<int>::iterator it;   //C98标准

    // 遍历 两种方式
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<' ';
    }
    cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;

    // 常用接口（常用的）
    
    // 向量尾插入push_back()   void push_back (const value_type& val);
    v.push_back(10);  //插入一个数据10

    // 向量尾删除pop_back()    void pop_back();
    v.pop_back();

    // 插入insert()
    // 插入单一数据到指定位置： iterator insert (iterator position, const value_type& val);
    // 插入一段数据到指定位置： void insert (iterator position, size_type n, const value_type& val);
    // 插入一段别的容器的数据到指定位置： void insert (iterator position, InputIterator first, InputIterator last);
    v.insert(v.begin(),10);     //在向量最前端插入数据10
    v.insert(v.begin(),5,20);   //在向量最前端插入5个数据20
    
    vector<int> k(2,50);   //创建一个新的向量k,其拥有2个元素内容均为50
    v.insert(v.begin(),k.begin(),k.end());  //在向量v最前端插入向量K的全部内容

    // 删除erase()   iterator erase (iterator position);     iterator erase (iterator first, iterator last);
    v.erase(v.begin());     //删除第一个元素
    v.erase(v.begin(),v.begin()+4); //删除从第一个开始后4个元素（包括第一个）

    // 清空clear()    void clear();
    v.clear();      //清空向量

    // 数据大小size()  size_type size() const;
    cout<<v.size()<<endl;   //输出5

    // 已开辟最大宽度capacity()   size_type capacity() const;
    cout<<v.capacity()<<endl;   //输出13
    
    system("pause");
    return 0;
}

