#include<iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
  
//二分查找算法，找不到就返回-1，找到了就返回值
int binary_search(int * list,int len,int target) {
    int low = 0;
    int hight = len-1;
    int middle;
    while(low <= hight) {
        middle = (low + hight)/2;
        if(list[middle] = target) {
            printf("Yes! location : %d\n",middle);
            return list[middle];
        } else if(list[middle] > target) {
            hight = middle -1;
        } else if(list[middle] < target) {
            low = middle + 1;
        }
    }
    printf("Not have this number!\n");
    return -1;
}
  

// 块查找  
struct index 
{ 
    //定义块的结构
    int key;
    int start;
  
} newIndex[3];  //定义结构体数组

int search(int key, int a[]);
  
int cmp(const void *a,const void* b)
{
    return (*(struct index*)a).key>(*(struct index*)b).key?1:-1;
}
   
int search(int key, int a[])
{
    int i, startValue;
    i = 0;
    while (i<3 && key>newIndex[i].key) 
    { 
        // 确定在哪个块中，遍历每个块，确定key在哪个块中
        i++;
    }
    if (i>=3) 
    { 
        //大于分得的块数，则返回0
        return -1;
    }
    startValue = newIndex[i].start; //startValue等于块范围的起始值
    while (startValue <= startValue+5 && a[startValue]!=key)
    {
        startValue++;
    }
    if (startValue>startValue+5) 
    { 
        //如果大于块范围的结束值，则说明没有要查找的数
        return -1;
    }
  
    return startValue;
}
  


int main(){
    int Shangping[6]={10,10,9,10,10,10};

    // 顺序查找
    for(int i=0;i<6;i++){
        if(Shangping[i]==9){
            cout << "location : " << i+1 << endl;
            break;
        }
    }

    // 折半查找
    int aa[] = {2,4,5,8,9,44};
    int bb = binary_search(aa,sizeof(aa)/4,5);
    printf("bb=%d\n",bb);
    printf("Hello world!\n");


    // 块查找
    int i, j=-1, k, key;
    int a[] = {33,42,44,38,24,48, 22,12,13,8,9,20, 60,58,74,49,86,53};
    //确认模块的起始值和最大值
    for (i=0; i<3; i++) 
    {
        newIndex[i].start = j+1; //确定每个块范围的起始值
        j += 6;
        for (int k=newIndex[i].start; k<=j; k++) 
        {
            if (newIndex[i].key<a[k]) 
            {
                newIndex[i].key = a[k];
            }
        }
    }
    //对结构体按照 key 值进行排序
    qsort(newIndex,3, sizeof(newIndex[0]), cmp);
    //输入要查询的数，并调用函数进行查找
    printf("Input number want to find: \n");
    scanf("%d", &key);
    k = search(key, a);
    //输出查找的结果
    if (k>0) 
    {
        printf("Yes! location : %d\n",k+1);
    }
    else
    {
        printf("Not have this number!\n");
    }


    system("pause");
    return 0;
    
}