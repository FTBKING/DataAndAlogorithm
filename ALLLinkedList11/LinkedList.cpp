#include <iostream>
using namespace std;

//定义节点
struct Node {
    int data;
    Node* Next;
};
//待改造为泛型
class OneWayLinkedList {
public:
    //维护一个size
    int size = 0;
    //若默认初始化，就什么都不要做，后面Insert方法需要一个Head为NULL的头部
    OneWayLinkedList() {
        Head = NULL;
    }
    //插入初始值型初始化
    OneWayLinkedList(int data) {
    //堆区开辟内存空间
    Head = new Node();
    //装入data，并且下一个节点为空
    Head->data = data;
    Head->Next = NULL;
}
    ~OneWayLinkedList() {
        //释放堆区内存
        if (Head!=NULL) {
            delete Head;
            Head = NULL;
        }
    }
    //头部插入节点
    void AddFirst(int data) {
        //先存个temp节点
        Node* temp = new Node();
        temp->data = data;
        temp->Next = Head;
        //if (Head != NULL){ temp->Next = Head; } //可以简化为直接赋值temp->Next = Head，1.如果Head为NULL，则为NULL。2.不为NULL，下一个就是Head的地址
        Head = temp;
    }
    //尾部插入节点,返回值为int，即为插入在第几个索引位置
    int AddLast(int data) {
        //如果头节点还没有数据就插到头节点
        if (Head == NULL) {
            Head = new Node();
            Head->data = data;
            Head->Next = NULL;
            return 0;
        }
        //头节点有数据
        //先向堆区申请一份内存存新的节点
        //指定data，并且next设置为null
        Node* temp = new Node();
        temp->data = data;
        temp->Next = NULL;
        //从头指针开始遍历
        Node* temp1 = Head;
        int currentIndex = 1;
        while (temp1->Next != NULL) {
            //就向后找到第一个Next地址为空的节点
            temp1 = temp1->Next;
            currentIndex++;
        }
        //给这个节点连上新增的节点
        temp1->Next = temp;
        //返回当前位置索引
        return currentIndex;
    }
    //在第n个位置插入节点
    void InsertatNpostion(int data,int n) {
        //创建一个临时节点，存要插入的数据
        Node* temp1 = new Node();
        temp1->data = data;
        temp1->Next = NULL;
        //如果要在第一个位置插入,直接套用AddFirst的逻辑
        if (n==1) {
            temp1->Next = Head;
            Head = temp1;
            //别忘了退出
            return;
        }
        //在其他位置插入，先创建个临时节点存为Head
        Node* temp2 = new Node();
        temp2 = Head;
        //从Head开始向后遍历到要插入的位置的前一个位置
        for (int i=1;i<n-1;i++) {
            temp2 = temp2->Next;
        }
        //先将要插入的节点的下一个设置成当前位置原有节点的下一个
        temp1->Next = temp2->Next;
        //然后再把当前位置原有节点的下一个改成要插入的节点
        temp2->Next = temp1;
    }
    //删除第n个位置的数据
    bool deleteAtNPostion(int n) {
        //若n=1
        if (n==1) {
            //先把头节点的下一个节点存为temp
            Node* temp = Head->Next;
            //删除头节点的数据，并且指定空指针，防止野指针出现
            delete Head;
            Head = NULL;
            //把头节点的下一个节点变为Head
            Head = temp;
            return true;
        }
        //若n!=1
        //1.找到n-1和n位置的数据
        //i=1 p = 2
        //i=2 p = 3
        //i=3 p = 4
        //从头指针开始
        Node* temp = Head;
        for (int i = 1;i<n;i++) {
            temp = temp->Next;
            if (i < n-2) continue;

        }
        //2.先将n-1位置的数据的next指向为n位置的next
        //3.然后删除n位置的数据

    }
    //获取指定位置索引的数据
    int GetDataByIndex(int index) {
        //0直接返回头指针的数据
        if (!index) {
            return Head->data;
        }
        //根据确定的索引，指定要遍历的次数
        //1.没有指定索引
        Node* temp1 = Head;
        int currentIndex = 0;
        while (temp1->Next != NULL && currentIndex != index) {
            //就向后找到第一个Next地址为空的节点
            temp1 = temp1->Next;
            currentIndex++;
        }
        if (currentIndex == index) {
            return temp1->data;
        }else {
            return -1;
        }
    }
private:
    Node* Head;
};
void test01() {
    OneWayLinkedList list(10);
    //帮我多造几组数据
    cout << list.AddLast(10)<<endl;
    cout << list.AddLast(20)<<endl;
    cout << list.AddLast(30)<<endl;
    cout << list.AddLast(40)<<endl;
    //获取指定位置索引的数据
    cout << list.GetDataByIndex(0)<<endl;
    cout << list.GetDataByIndex(1)<<endl;
    cout << list.GetDataByIndex(2)<<endl;
    cout << list.GetDataByIndex(3)<<endl;
    cout << list.GetDataByIndex(4)<<endl;
}
void test02() {
    OneWayLinkedList list;
    list.InsertatNpostion(2,1);
    list.InsertatNpostion(3,2);
    list.InsertatNpostion(4,1);
    list.InsertatNpostion(5,2);
    list.InsertatNpostion(7,7);
}
int main() {
    //test01();
    test02();
    return 0;
}