#include <iostream>
#include<stdexcept>
using namespace std;

double divide(double a, double b) {
    if (b == 0) {
        //抛出异常，可以是字符串类型的异常
        throw "除数不能为0";
    }
    return a / b;
}
int main() {
    system("chcp 65001");
    try {
        cout<<divide(10, 0)<<endl;
    } catch (const char* msg) { //在捕获时捕获对应类型的异常
        cout<<"捕获到错误"<<msg<<endl;
    }
    //还可以抛出标准异常，更加规范
    try {
        throw runtime_error("除数不能为0");
    } catch (const runtime_error& e) { //在捕获时捕获对应类型的异常
        //获取异常信息，打印出来
        cout<<"捕获到错误"<<e.what()<<endl;
    }
    return 0;
}