/* Date   : 2022.03.15
Descibe   : Gives you an array of integers nums,
            true if any value appears in the array at least twice;
            false if each element in the array is different.

Note      : None.

author    : YA  */

#include <iostream>
using namespace std;


bool qucik_sort(int* a,int low,int high) {
    int i,j,temp;
    i=low;
    j=high;
    if(low<high) {
        temp=a[low];    //设置枢轴
        while(i!=j) {
            while(j>i&&a[j]>=temp) {

                if (a[j] == temp)
                {
                    /* code */
                    return true;
                }
                --j;
                
            }
            if(i<j) {
                a[i]=a[j];
                ++i;


            }
  
            while(i<j&&a[i]<temp) {
                ++i;
            }
            if(i<j) {
                a[j]=a[i];
                --j;

            }
        }
        a[i]=temp;
        qucik_sort(a,low,i-1);
        qucik_sort(a,i+1,high);

        return false;

    }
}    


bool containsDuplicate(int* nums, int numsSize){

    bool status = true;

    status = qucik_sort(nums , 0 , numsSize - 1);

    return  status;

}


// Leetcode example

int partition(int* nums,int low,int high){
    //快排的划分算法
    int pivot = nums[(low+high)/2];  //中间元素设置为枢轴
    //将第一元素与枢轴对换位置，最小化改动原算法
    nums[(low+high)/2] = nums[low];
    nums[low] = pivot;

    while(low<high){
        while(low<high&&nums[high]>=pivot) --high;
        nums[low] = nums[high]; //小的放左边
        while(low<high&&nums[low]<=pivot) ++low;
        nums[high] = nums[low]; //大的放右边

    }
    nums[low]=pivot;    //枢轴元素放入最终位置
    return low;         //放回枢轴的位置，方便下次划分
}

void quickSort(int* nums,int low,int high){
    if(low<high){
        int pivotpos = partition(nums,low,high);
        quickSort(nums,low,pivotpos-1);
        quickSort(nums,pivotpos+1,high);

    }
}

bool Leetcode_containsDuplicate(int* nums, int numsSize){
    if(numsSize==0) return false;
    int i=0;
    quickSort(nums,0,numsSize-1);
    while(i<numsSize-1){
        if(nums[i]==nums[++i])  return true;
    }
    return false;
}


int main(){

    int a[10] = {1,1,1,3,3,4,3,2,4,2};
    int *p = &a[0];
    int numsSize = 10;

    int count = 100;
    int b[count] = {0};
    for (int i = 0; i < count; i++)
    {
        /* code */
        b[i] = i;
    }
    b[50] = 1;
    

    cout <<  containsDuplicate(a , numsSize) << endl;
    cout <<  containsDuplicate(b , count) << endl;

    system("pause");
    return 0;

}