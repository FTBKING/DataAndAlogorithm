#include <iostream>
#include <stack>
#include<map>
using namespace std;

bool ParenthesisBalance(string str) {
    //定义1个映射表，将右括号与左括号对应起来
    map<char,char> m = {{'(',')'},{'[',']'},{'{','}'}};
    //获取此字符串的长度
    int n = str.size();
    //创建1个栈
    stack<char> s;
    //遍历字符串
    for (int i=0;i<n;i++) {
        //如果是左括号的一种，进栈
        if (str[i]=='(' || str[i]=='{' || str[i]=='[') {
            s.push(str[i]);
        }else if (str[i]==')' || str[i]=='}' || str[i]==']') {//如果是右括号的一种
            //先判断栈是否为空或栈顶元素是否与当前右括号匹配
            //知识点：map[key]可以得到映射表中对应键的值
            if (s.empty() || m[s.top()] != str[i]) {
                //直接返回错误，因为没有对应的左括号了，不平衡
                return false;
            } else {
                //不为空就，出栈
                s.pop();
            }
        }
    }
    //遍历进行完所有操作后，如果平衡则栈应该为空，不平衡就不为空
    return s.empty();
}
int main() {
    system("chcp 65001");
    string a = "{[(])}";
    cout<<ParenthesisBalance(a)<<endl;
    return 0;
}