#include <iostream>
#include<stack>
#include<string>
#include<cctype>
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

int main() {
    system("chcp 65001");
    //单个字符转整型，用c - '0'
    int a = '2'-'0';
    int b = '5'-'0';
    cout<<a+b<<endl;
    //整型转字符,用单个整数+'0'即可
    char c = 6 + '0';
    cout<<c<<endl;
    cout<<EvaluatePostfix("23*54*+9-")<<endl;
    return 0;
}