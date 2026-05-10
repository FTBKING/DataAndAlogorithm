#include <iostream>
using namespace std;

//双向链表，每个节点存储前一个节点和后一个节点的地址
template<typename T>
class DoubleLinkedList {
public:
    struct Node {
        T data;
        //前一个节点
        Node* prev;
        //后一个节点
        Node* next;
    };
    //头节点成员
    //注意：指针一定要初始化为nullptr
    //对原始指针来说，默认初始化不做事,可能会指向垃圾内存
    Node* head = nullptr;
    //新点子：维护一个尾指针，方便在尾部插入节点
    Node* tail = nullptr;
    //头部插入节点
    void InsertAtHead(T data) {
        //创建一个节点
        Node* newNode = GetNewNode(data);
        //如果链表为空,(头节点和尾节点都为空)
        //建议全部满足，防止硬件层问题，导致程序出错
        if (head == nullptr && tail == nullptr) {
            //头节点=尾节点=新节点
            //语法糖：从右向左赋值 等同于 head = newNode; tail = newNode
            head = tail = newNode;
            return;
        }
        //原来的头节点不为空
        //将原来的头节点的前一个改成新节点
        head->prev = newNode;
        //将新节点的下一个改成原来的头节点
        newNode->next = head;
        //头节点改成新节点
        head = newNode;
        return;
    }
    //尾部插入节点
    void InsertAtTail(T data) {
        //创建一个新节点
        Node* newNode = GetNewNode(data);
        //如果链表为空,(头节点和尾节点都为空)
        //建议全部满足，防止硬件层问题，导致程序出错
        if (head == nullptr && tail == nullptr) {
            //头节点=尾节点=新节点
            //语法糖：从右向左赋值 等同于 head = newNode; tail = newNode
            head = tail = newNode;
            return;
        }
        //将原来的尾节点的下一个改成新节点
        tail->next = newNode;
        //将新节点的上一个改成原来的尾节点
        newNode->prev = tail;
        //最后不要忘了把新节点设置为新的尾节点
        tail = newNode;
        return;
    }
    //正向遍历链表
    void Print(Node* node) {
        //从传入的节点开始正向遍历链表
        while (node!=nullptr) {
            cout<<node->data<<" ";
            node = node->next;
        }
    }
    //反向遍历链表
    void PrintReverse(Node* node) {
        //从传入的节点开始反向遍历链表
        while (node!=nullptr) {
            cout<<node->data<<" ";
            node = node->prev;
        }
    }
private:
    //获得新节点的方法
    Node* GetNewNode(T data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        return newNode;
    }
};
int main() {
    system("chcp 65001");
    DoubleLinkedList<int> DL;
    DL.InsertAtTail(1);
    DL.InsertAtTail(2);
    DL.InsertAtTail(3);
    DL.InsertAtTail(4);
    DL.Print(DL.head);
    cout<<endl;
    DL.PrintReverse(DL.tail);


    return 0;
}