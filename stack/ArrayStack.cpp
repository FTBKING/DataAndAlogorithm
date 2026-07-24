#include <iostream>
#define MAX_SIZE 111
using namespace std;
template<typename T>
class ArrayStack {
public:    //一个初始数组
    T a[MAX_SIZE];
    //标记栈顶索引
    int top = -1;
    //Push操作进栈，返回当前top索引
    int Push(T data) {
        if (top == MAX_SIZE-1) {
            cout<<"栈已经满了，无法进栈"<<endl;
            return top;
        }
        a[++top] = data;
        return top;
    }
    //Pop操作出栈
    T Pop() {
        if (top == -1) {
            cout<<"栈空，无法出栈"<<endl;
            return NULL;
        }
        top--;
        return a[top+1];
    }
    //获取栈顶元素
    T Top() {
        if (top == -1) {
            cout<<"栈空，无栈顶元素"<<endl;
            return NULL;
        }
        return a[top];
    }
    bool isEmpty() {
        return (top==-1)?true:false;
    }

};
int main() {
    system("chcp 65001");
    //定义一个栈
    ArrayStack<int> stack;
    //帮我测试所有方法
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    cout<<"栈顶元素为："<<stack.Top()<<endl;
    cout<<"栈是否为空："<<stack.isEmpty()<<endl;
    return 0;
}