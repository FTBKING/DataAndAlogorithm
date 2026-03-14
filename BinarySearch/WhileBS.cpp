#include <iostream>
using namespace std;

//前向声明
int WhileBSGetIndex(int arr[], int size, int target);

int main() {
    //while版二分查找
    //解决问题：一个排好序（升序/降序）的数组中找到特定的值
    //定义一个有序数组
    int arr[] = {2,6,13,21,36,47,63,81,97};
    cout<<sizeof(arr)/sizeof(arr[0])<<endl;
    //使用二分查找函数
    int result = WhileBSGetIndex(arr,sizeof(arr)/sizeof(arr[0]),13);
    if (result == -1) {
        cout<<"查找的值不存在"<<endl;
    }else {
        cout<<"查找的值存在，索引为："<<result<<endl;
    }
    return 0;
}
//定义二分查找函数
int WhileBSGetIndex(int arr[], int size, int target) {
    //定义start,end游标
    int start = 0;
    int end = size - 1;
    //定义一个mid
    int mid = 0;
    //进入循环,如果s=e说明没找到，返回-1
    while (start<=end) {
        //先通过start,end计算出mid的值
        //mid = (start+end)/2; //可能会溢出，改为下面的写法
        mid = start + (end - start) / 2; //防止溢出
        //接下来进入三种情况
        //注意：target在前判断，别搞错关系
        if (target == arr[mid]) { //第一种情况mid=target直接返回index
            return mid;
        }else if (target < arr[mid]) { //第二种情况target<arr[mid]，舍弃后半部分
            end = mid - 1;
        }else if (target > arr[mid]) { //第三种情况target>arr[mid]，舍弃前半部分
            start = mid + 1;
        }
    }
    return -1;

}
