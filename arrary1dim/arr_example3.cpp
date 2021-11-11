// 计算数组的冒泡排序 从小到大  升序

/* 
1.比较相邻的元素。若第一个比第二个大，就交换他们两个。
2.对每一个相邻的元素做同样的工作，执行完毕后，找到第一个最大值。
3.重复以上步骤，每次比较次数-1，直到不需要比较。 
*/

#include <iostream>

using namespace std;

int main()
{

    //Aarry_example3

    int arr[10] = {4,2,8,0,5,7,1,3,6,9};

    int start = 0;
    int end = 0;

    int temp = 0;

    end = sizeof(arr)/sizeof(arr[0]) ;
    cout << end << "\n" << endl ;
  

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] <<"  ";
    }

    cout << "\n" << "\n";

//排序的总轮数 = 元素个数 - 1 即最后一个元素的索引值  ----外循环
//每轮对比次数 = 元素个数 - 排序轮数 - 1    ---内循环

    for (int i = 0; i < end - 1; i++)
    {
        //cout << i <<"\n";

        for (int j = 0; j < (end - i - 1); j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] <<"  ";
    }
      
    system("pause");

    return 0;
}