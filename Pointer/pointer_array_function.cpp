// 指针  数组  函数
// 封装成一个函数，利用冒泡排序，实现对整形数组的升序降序

#include <iostream>

using namespace std;

// 冒泡排序  --- 定义指针变量  长度变量   
//           --- 传入 arr -- p = arr; -- 将数组地址传递 -- 使得相当于在操作 数组arr
void Bubble_Sort(int * p ,int len)
{    
    int temp = 0;

//排序的总轮数 = 元素个数 - 1 即最后一个元素的索引值  ----外循环
//每轮对比次数 = 元素个数 - 排序轮数 - 1    ---内循环

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < (len - i - 1); j++)
        {
            if( p[j] > p[j+1] )
            {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    
    // 使用指针遍历整个数组！
    for (int i = 0; i < len; i++)
    {
        cout << *(p + i )<< " ";
    }
    cout <<"\n"<< endl;
}


int main()
{   
    // 定义一个数组
    int arr[] = { 17,18,19,4,3,6,9,1,2,10,8,7,5,15,16 };

    // 获取数组长度
    int len = sizeof(arr)/sizeof(arr[0]);

    // 调用函数
    Bubble_Sort(arr,len);

    system("pause");
    return 0;
}