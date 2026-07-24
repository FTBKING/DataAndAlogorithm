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
        //default也可以代表括号，优先级为0
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
        //将括号逻辑放到运算符逻辑之前，不用区分是运算符还是括号
        //第二个判断，是开括号？
        else if (c == '(') {
            //是左括号就进栈
            operators.push(c);
        }
        //第三个判断，是闭括号？
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                //如果没到栈中的第一个开括号，就拿栈顶的拼接res
                res +=operators.top();
                //然后出栈
                operators.pop();
            }
            //最后把开括号出栈
            operators.pop();
        }
        else if (c != ' '){
            //原则1：如果列表不为空，并且栈顶元素的优先级大于等于当前操作符的优先级
            //弹出栈中所有元素，拼接到res后面
            while (!operators.empty()
                && IstopLEcurrent(operators.top(), c)
                ) {
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
    string Infix = "1*(2+3)";
    string Postfix = InfixToPostfix(Infix);
    cout<<"后缀表达式为："<<Postfix<<endl;
    return 0;
}