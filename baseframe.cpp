#include <iostream>
using namespace std;
//目前知道的能放的类型有：整数和枚举，浮点型不能放
template<typename T,int Size>
class A {
    public:
        void Print() {
            cout<<Size<<endl;
        }
};

int main() {
    A<int,10> a;
    a.Print();
    return 0;
}