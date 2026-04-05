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
    //默认初始化
    OneWayLinkedList() {
    //堆区开辟内存空间
    Head = new Node();
    //全部为空
    Head->data = NULL;
    Head->Next = NULL;
}
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
    //插入节点,返回值为int，即为插入在第几个索引位置
    int Insert(int data) {
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
        int currentIndex = 0;
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
    //获取头数据
    int GetHeadData() {
        return Head->data;
    }
private:
    Node* Head;
};
int main() {
    OneWayLinkedList list(10);
    cout << list.GetHeadData() << endl;
    cout << list.Insert(20)<<endl;
    cout << list.Insert(30)<<endl;
    cout << list.Insert(40)<<endl;
    return 0;
}