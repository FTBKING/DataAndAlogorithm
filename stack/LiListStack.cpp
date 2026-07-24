#include <iostream>
using namespace std;
template<typename T>
class LinkedListStack{
public:
    //定义节点结构体
    struct Node {
        //数据
        T data;
        //下一个节点
        Node* link;
    };
    //因为是栈所以要定义1个top节点指针标记栈顶
    Node* top = nullptr;
    //Push进栈操作
    void Push(T data) {
        //top先不改，top是获得栈顶的唯一信息
        //得到一个新节点
        Node* temp = new Node();
        temp->data = data;
        //先把新节点的link改成top
        temp->link = top;
        //再把top指向新节点
        top = temp;
        //无论栈是否为空，逻辑都一样
        return;
    }
    //Pop出栈操作
    void Pop() {
        //如果栈为空，直接返回
        if (top == nullptr) {
            return;
        }
        //存一个当前栈顶的指针
        Node* temp = top;
        //将top指向当前栈顶的下一个节点
        top = temp->link;
        //释放当前栈顶空间
        delete temp;
        temp = nullptr;
        return;
    }
    //Top得到栈顶元素
    T Top() {
        //如果栈为空，直接返回
        if (top == nullptr) {
            return T();
        }
        //返回栈顶元素
        return top->data;
    }
};
int main() {
    system("chcp 65001");
    //创建一个栈对象
    LinkedListStack<int> stack;
    //帮我测试所有方法
    stack.Push(1);
    cout << stack.Top() << endl;
    stack.Push(2);
    cout << stack.Top() << endl;
    stack.Pop();
    cout << stack.Top() << endl;
    stack.Pop();
    cout << stack.Top() << endl;
    return 0;
}