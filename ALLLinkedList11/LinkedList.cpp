#include <iostream>
using namespace std;

//定义节点
struct Node {
    int data;
    Node* Next;
};
//待改造为泛型
class OneWayLinkedList {
public:
    //维护一个size
    int size = 0;
    //插入初始值型初始化
    OneWayLinkedList(int data) {
    //堆区开辟内存空间
    Head = new Node();
    //装入data，并且下一个节点为空
    Head->data = data;
    Head->Next = NULL;
}
    ~OneWayLinkedList() {
        //释放堆区内存
        if (Head!=NULL) {
            delete Head;
            Head = NULL;
        }
    }
    //头部插入节点
    void AddFirst(int data) {
        //先存个temp节点
        Node* temp = new Node();
        temp->data = data;
        temp->Next = Head;
        //if (Head != NULL){ temp->Next = Head; } //可以简化为直接赋值temp->Next = Head，1.如果Head为NULL，则为NULL。2.不为NULL，下一个就是Head的地址
        Head = temp;
    }
    //尾部插入节点,返回值为int，即为插入在第几个索引位置
    int AddLast(int data) {
        //如果头节点还没有数据就插到头节点
        if (Head->data == NULL) {
            Head->data = data;
            Head->Next = NULL;
            return 0;
        }
        //头节点有数据
        //先向堆区申请一份内存存新的节点
        //指定data，并且next设置为null
        Node* temp = new Node();
        temp->data = data;
        temp->Next = NULL;
        //从头指针开始遍历
        Node* temp1 = Head;
        int currentIndex = 1;
        while (temp1->Next != NULL) {
            //就向后找到第一个Next地址为空的节点
            temp1 = temp1->Next;
            currentIndex++;
        }
        //给这个节点连上新增的节点
        temp1->Next = temp;
        //返回当前位置索引
        return currentIndex;
    }
    //获取指定位置索引的数据
    int GetDataByIndex(int index) {
        //0直接返回头指针的数据
        if (!index) {
            return Head->data;
        }
        //根据确定的索引，指定要遍历的次数
        //1.没有指定索引
        Node* temp1 = Head;
        int currentIndex = 0;
        while (temp1->Next != NULL && currentIndex != index) {
            //就向后找到第一个Next地址为空的节点
            temp1 = temp1->Next;
            currentIndex++;
        }
        if (currentIndex == index) {
            return temp1->data;
        }else {
            return -1;
        }
    }
private:
    Node* Head;
};
int main() {
    OneWayLinkedList list(10);
    //帮我多造几组数据
    cout << list.AddLast(10)<<endl;
    cout << list.AddLast(20)<<endl;
    cout << list.AddLast(30)<<endl;
    cout << list.AddLast(40)<<endl;
    //获取指定位置索引的数据
    cout << list.GetDataByIndex(0)<<endl;
    cout << list.GetDataByIndex(1)<<endl;
    cout << list.GetDataByIndex(2)<<endl;
    cout << list.GetDataByIndex(3)<<endl;
    cout << list.GetDataByIndex(4)<<endl;
    return 0;
}