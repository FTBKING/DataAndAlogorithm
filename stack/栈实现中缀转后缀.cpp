#include <iostream>
#include<stack>
#include<cctype>
using namespace std;

//优先级方法
int Priority(char c) {
    //用switch返回优先级
    switch (c) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}
//判断栈顶元素是否大于等于当前操作符的优先级
bool IstopLEcurrent(char top, char current) {
    //如果栈顶元素是指数，当前操作符是指数，返回false,不弹出
    if (top == '^' && current == '^')
    return false;
    //判断栈顶元素的优先级是否大于等于当前操作符的优先级
    return Priority(top) >= Priority(current);
}

string InfixToPostfix(string Infix) {
    //创建1个符号存取栈
    stack<char> operators;
    //创建1个结果字符串
    string res;
    for (auto c:Infix) {
        //第一个判断，如果是数字，则拼到res后面
        if (isdigit(c)) {
            res += c;
        }
        //第二个判断，假设不是数字就是操作符
        else if (c != ' '){
            //原则1：如果列表不为空，并且栈顶元素的优先级大于等于当前操作符的优先级
            //弹出栈中所有元素，拼接到res后面
            if (!operators.empty() && IstopLEcurrent(operators.top(), c)) {
                res += operators.top();
                operators.pop();
            }
            //不满足原则1则进栈
            operators.push(c);
        }
    }
    //到末尾了，弹出所有栈元素，拼接到res后面
    while (!operators.empty()) {
        res += operators.top();
        operators.pop();
    }
    return res;
}

int main() {
    system("chcp 65001");
    string Infix = "1 + 2 - 3 * 4 ^ 5 ^ 6";
    string Postfix = InfixToPostfix(Infix);
    cout<<"后缀表达式为："<<Postfix<<endl;
    return 0;
}