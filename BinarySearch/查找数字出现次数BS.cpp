#include <iostream>
using namespace std;

int FindCountTarget(int* arr,int size,int target,bool searchFirst) {
    //首尾游标
    int low = 0;
    int high = size - 1;
    //声明result并令其=-1
    int result = -1;
    //声明mid
    int mid = 0;
    while (low<=high) {
        //得到mid
        mid = low+(high-low)/2;
        //依旧是三种情况
        if (target == arr[mid]) {
            result = mid; //将直接返回改成为result赋值，为了继续寻找第一个
            if (searchFirst) {
                high = mid -1; //找第一次出现所以缩减游标到mid之前，向前寻找
            }else {
                low = mid +1; //找最后一次出现所以缩减游标到mid之前，向后寻找
            }
        }else if (target < arr[mid]) {
            high = mid -1;
        }else {
            low = mid +1;
        }
    }
    return result;//最后返回result
}

int main() {
    //测试用例
    int arr[] = {1,1,3,3,5,5,5,5,5,9,9,11};
    int size = sizeof(arr)/sizeof(arr[0]);
    //找到第一个5的位置
    int firstOcc = FindCountTarget(arr,size,9,true);
    if (firstOcc != -1) {
        int lastOcc = FindCountTarget(arr,size,9,false);
        cout << "9出现了"<<lastOcc-firstOcc+1<<"次"<<endl;
    }else {
        cout<<"数组中不存在目标值"<<endl;
    }

    return 0;
}