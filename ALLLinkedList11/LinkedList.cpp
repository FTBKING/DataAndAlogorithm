#include <iostream>
using namespace std;
//改造为泛型链表
template <typename DataType>
//如何做到每个节点存不同类型的数据？
class OneWayLinkedList {
public:
    //定义节点
    struct Node {
        DataType data;
        Node* Next;
    };
    //维护一个size
    int size = 0;
    //头节点
    Node* Head;
    //若默认初始化，就什么都不要做，后面Insert方法需要一个Head为NULL的头部
    OneWayLinkedList() {
        Head = NULL;
    }
    //插入初始值型初始化
    OneWayLinkedList(DataType data) {
    //堆区开辟内存空间
    Head = new Node();
    //装入data，并且下一个节点为空
    Head->data = data;
    Head->Next = NULL;
    //更新size
    size = 1;
}
    ~OneWayLinkedList() {
        //释放堆区内存
        if (Head!=NULL) {
            delete Head;
            Head = NULL;
        }
    }
    //头部插入节点
    void AddFirst(DataType data) {
        //先存个temp节点
        Node* temp = new Node();
        temp->data = data;
        temp->Next = Head;
        //if (Head != NULL){ temp->Next = Head; } //可以简化为直接赋值temp->Next = Head，1.如果Head为NULL，则为NULL。2.不为NULL，下一个就是Head的地址
        Head = temp;
        //更新size
        size++;
    }
    //尾部插入节点,返回值为int，即为插入在第几个索引位置
    int AddLast(DataType data) {
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
        //更新size
        size++;
        //返回当前位置索引
        return currentIndex;
    }
    //在第n个位置插入节点
    void InsertatNpostion(DataType data,int n) {
        //创建一个临时节点，存要插入的数据
        Node* temp1 = new Node();
        temp1->data = data;
        temp1->Next = NULL;
        //如果超出size+1，直接返回
        if (n > size + 1 || n<1) {
            cout<<"无法在非头/尾部后的位置插入"<<endl;
            return;
        }
        //如果要在第一个位置插入,直接套用AddFirst的逻辑
        if (n==1) {
            temp1->Next = Head;
            Head = temp1;
            //更新size
            size++;
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
        //更新size
        size++;
    }
    //删除第n个位置的数据
    bool deleteAtNPostion(int n) {
        //先temp1存上头节点
        Node* temp1 = Head;
        //若n=1
        if (n==1) {
            //将Head变为下一个节点
            Head = temp1->Next;
            //删除头节点的数据
            delete temp1;
            temp1 = NULL;
            size--;
            return true;
        }
        //n!=1，那么就遍历到n-1个节点
        for (int i=1;i<n-1;i++) {
            temp1 = temp1->Next;
        }
        //此时到达n-1个节点
        //存个temp2，表示第n个节点，也是当前要删除的节点
        Node* temp2 = temp1->Next;
        //修复前一个节点的Next指向，指向第n个节点后面的节点
        temp1->Next = temp2->Next;
        //释放第n个节点的空间
        delete temp2;
        temp2 = NULL;
        //
        size--;
        return true;
    }
    Node* Reverse() {
        //反转链表
        //先存三个局部Node，表示当前、上一个、下一个节点
        Node *current,*prev,*next;
        //当前节点起始为Head，所以prev是NULL
        current = Head;
        prev = NULL;
        //如果当前节点没到最后1个，不是NULL就循环
        while (current != NULL) {
            //反转链表，要将当前节点指向后一个节点改为前一个节点
            //所以要先存起来下一个节点给next
            next = current->Next;
            //再更改当前节点的指向
            current->Next = prev;
            //移动到下一个节点进行操作，但现需要将prev上一个节点设置为当前节点
            //因为移动后就不知道上一个节点是谁
            prev = current;
            //移动current到下一个节点,注意是已经存起来的next
            current = next;
        }
        //然后将Head设置为最后1个节点，就可以完成反转了
        Head = prev;
        //返回Head
        return Head;
        //感悟：这就是迭代器
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
    //while遍历
    void PrintListWhile() {
        Node* temp = Head;
        //这里应该是temp!=NULL，如果是temp->Next!=NULL，没到最后1个节点就会停止
        while(temp != NULL) {
            cout<<temp->data<<" ";
            temp = temp->Next;
        }
        cout<<endl;
    }
    //从一个Node开始，递归正向遍历
    void PrintListRc(Node* p) {
        //p为NULL时作为出口，出栈
        if (p == NULL) {
            return;
        }
        //正向遍历，先打印，在进栈
        cout<<p->data<<" ";
        //传入下一个节点
        PrintListRc(p->Next);
        //出栈时返回
        return;
    }
    //递归反向遍历
    void PrintListReverseRc(Node* p) {
        //p为NULL时作为出口，出栈
        if (p == NULL) {
            return;
        }
        //反向遍历，先进栈到最后1个节点
        //注意：别写成正向的调用了
        PrintListReverseRc(p->Next);
        //出栈的时候就是从后往前打印
        cout<<p->data<<" ";
        //出栈时返回
        return;
    }
    //递归反转链表
    void ReverseRc(Node* p) {
        //设置出口，到达最后一个节点
        //先把最后1个节点设置为头节点
        //再退出
        if (p->Next == NULL) {
            Head = p;
            return;
        }
        //递归调用自己，走到下一个节点
        ReverseRc(p->Next);
        //出栈时的操作
        //把下一个节点先存起来
        Node* next = p->Next;
        //将下一个节点的Next改为当前节点
        next->Next = p;
        //然后将当前节点的下一个节点设置为NULL
        //问题：这里为什么要设置为NULL
        //因为要让第一个节点做最后一个节点，这样执行到最后可以直接设置
        p->Next = NULL;
        return;
    }

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
    OneWayLinkedList<int> list;
    list.InsertatNpostion(2,1);
    list.InsertatNpostion(3,2);
    list.InsertatNpostion(4,1);
    list.InsertatNpostion(5,2);
    list.InsertatNpostion(7,6); //报错，问题：插入超出size+1返回会报错
}
void test03() {
    OneWayLinkedList list(10);
    //帮我多造几组数据
    list.AddLast(10);
    list.AddLast(20);
    list.AddLast(30);
    list.AddLast(40);
    //反转链表
    list.ReverseRc(list.Head);
    //输出
    //list.PrintListWhile();
    list.PrintListRc(list.Head);
    cout<<endl;
    list.PrintListReverseRc(list.Head);
    cout<<endl;
}
int main() {
    system("chcp 65001");
    //test01();
    //test02();
    test03();
    return 0;
}