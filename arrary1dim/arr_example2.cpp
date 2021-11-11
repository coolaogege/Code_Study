// 计算数组的元素互换

#include <iostream>

using namespace std;

int main(){

    //Aarry_example2

    int arr[5] = {1,5,4,3,2};

    int start = 0;
    int end = 0;

    int temp = 0;

    end = sizeof(arr)/sizeof(arr[0]) -1 ;
    cout << end << "\n" << endl ;

    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
      
    system("pause");

    return 0;
}