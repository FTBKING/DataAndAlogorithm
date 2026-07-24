#include <iostream>
#include <list>
using namespace std;

template<typename T>
class MyList {
private:
    //提供操作的数组
    T *a;
    //初始容量
    int capacity = 10;
    //当前元素个数
    int size = 0;
    //每次满了扩容的倍数
    int expandRatio = 2;
public:
    //构造方法
    MyList() {
        //初始化数组
        a = new T[capacity];
    }
    //析构方法
    ~MyList() {
        //释放数组
        if (a != nullptr) {
            delete[] a;
            a = nullptr;
        }
    }
    //容量和长度的getter
    [[nodiscard]] int capacity1() const {
        return capacity;
    }

    [[nodiscard]] int size1() const {
        return size;
    }
    //访问元素
    int get(int index) {
        //如果索引小于0,或大于等于size,则抛出异常
        if (index < 0 || index >=size) {
            //抛出异常
            throw out_of_range("索引越界");
        }
        //返回元素
        return a[index];
    }
    //更新元素
    void set(int index, T data) {
        //如果索引小于0,或大于等于size,则抛出异常
        if (index < 0 || index >=size) {
            //抛出异常
            throw out_of_range("索引越界");
        }
        //更新元素
        a[index] = data;
    }

    void expandArr() {
        //创建一个新的数组
        T* tempArr = new T[capacity*expandRatio];
        //将旧的数组的内容拷贝到新的数组里
        for (int i=0;i<size;i++) {
            tempArr[i] = a[i];
        }
        //释放数组空间
        delete[] a;
        //令当前数组指向新数组的首地址
        a = tempArr;
        //更新Capacity
        capacity = capacity*expandRatio;
    };

    //尾部添加元素
    void add(T data) {
        //元素超出容量时触发扩容机制
        if (size == capacity) {
            //扩容数组
            expandArr();
        }
        a[size] = data;
        size++;
    }
};

int main() {
    system("chcp 65001");
    MyList<int> list;
    return 0;
}