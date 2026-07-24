#include <cstring>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

void ReverseString(char* C,int n) {
    stack<char> s;
    //先进栈
    for (int i=0;i<n;i++) {
        s.push(C[i]);
    }
    //出栈
    for (int i=0;i<n;i++) {
        C[i] = s.top();
        s.pop();
    }
}



int main() {
    system("chcp 65001");
    char a[] = "HELLO";
    //注意char数组最后1个字符是\0,所以实际大小为6
    int n = size(a);
    ReverseString(a,n);
    //C++11更简洁的遍历数组的方式，auto关键字，和for配合
    for (auto x : a) {
        cout << x << " ";
    }
    return 0;
}