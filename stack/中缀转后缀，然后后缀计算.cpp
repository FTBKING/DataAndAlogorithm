#include <iostream>
#include<stack>
#include<string>
#include<cctype>
#include<cmath>
using namespace std;

int PerformCaculate(char operatorr, int oa1, int oa2) {
    switch (operatorr) {
        case '+':
            return (oa1 + oa2);
        case '-':
            return (oa1 - oa2);
        case '*':
            return (oa1 * oa2);
        case '/':
            return (oa1 / oa2);
        case '^':
            return (int)pow(oa1,oa2);
        default:
            cout<<"operatorr is not a valid operator"<<endl;
            return 0;
    }

}

int EvaluatePostfix(string pv) {
    //运算栈，只能用整型，因为可能是多位数，别的不好处理
    stack<int> s;
    //遍历输入的表达式
    //改用更现代的for(auto c:pv)遍历字符串
    for (auto c:pv){
        //导入cctype头文件，用isdigit函数判断是否是数字
        if (isdigit(c)) {
            //将字符转换为整型，再进栈
            s.push(c-'0');
        }
        //如果不是数字就是操作符，再判断一下是否有空格
        else if (c!=' ') {
            //两次出栈，执行运算
            int oa2 = s.top();
            s.pop();
            int oa1 = s.top();
            s.pop();
            int result = PerformCaculate(c,oa1,oa2);
            //将运算结果进栈，等待下一次运算使用
            s.push(result);
        }
    }
    return s.top();
}


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
            while (!operators.empty() && IstopLEcurrent(operators.top(), c)) {
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
    string Infix = "1 + 2 - 3 * 2 ^ 2 ^ 2";
    string Postfix = InfixToPostfix(Infix);
    cout<<"后缀表达式为："<<Postfix<<endl;
    cout<<EvaluatePostfix(Postfix)<<endl;
    return 0;
}