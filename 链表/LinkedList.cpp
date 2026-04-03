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
private:
    Node* Head;
};

int main() {
    return 0;
}