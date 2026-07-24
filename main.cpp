#include <iostream>
using namespace std;

template<class T>
void Test(T value) {
    cout<<value<<endl;
}
template<class T>
void Test1(T* value) {
    cout << value << endl;
}
int main() {
    int b =10;
    int* a = &b;
    int& c = b;
    //问题1：泛型可以代表什么类型？
    //1.基本类型和类,int，Customclass
    //2.复合类型，比如基本+指针：int*,CustomClass*，或是基本+引用类型int&，Customclass&
    //问题2：T*是什么？
    //是一种约束，传入的参数只能是指针，是其他的会报错
    Test(a);
    Test(b);
    Test(c);
    Test1(a);
    return 0;
}
