#include <iostream>
using namespace std;

int RecursiveBSGetIndex(int arr[], int start, int end, int target);

int main() {
    //递归版二分查找.
    //解决问题：一个排好序（升序/降序）的数组中找到特定的值
    //定义一个有序数组
    int arr[] = {2,6,13,21,36,47,63,81,97};
    cout<<sizeof(arr)/sizeof(arr[0])<<endl;
    //使用二分查找函数
    int result = RecursiveBSGetIndex(arr,0,sizeof(arr)/sizeof(arr[0])-1,13);
    cout<<result<<endl;
    return 0;
}

int RecursiveBSGetIndex(int arr[], int start, int end, int target) {
    //计算mid
    int mid = start + (end - start) / 2; //防止溢出
    //接下来进入三种情况
    //注意：target在前判断，别搞错关系
    if (target == arr[mid]) { //第一种情况mid=target直接返回index
        return mid;
    }else if (target < arr[mid]) { //第二种情况target<arr[mid]，舍弃后半部分
        return RecursiveBSGetIndex(arr, start, mid - 1, target);
    }else if (target > arr[mid]) { //第三种情况target>arr[mid]，舍弃前半部分
        return RecursiveBSGetIndex(arr, mid + 1, end, target);
    }
    return -1;
}

