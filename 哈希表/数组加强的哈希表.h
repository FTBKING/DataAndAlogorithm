//
// Created by lenovo on 2026/7/14.
//

#ifndef DATAANDALOGORITHM_数组加强的哈希表_H
#define DATAANDALOGORITHM_数组加强的哈希表_H
#include <random>
#include <unordered_map>
#include<vector>
using namespace std;

template<class K,class V>
class 数组加强的哈希表 {
private:
    //结构体
    struct Node {
        K _Key;
        V _Value;
    };
    //哈希表
    //键对应键，值对应在数组里的索引
    unordered_map<K,int> _map;
    vector<Node> _arr;
    int capacity;
    //犯错点，需要初始化随机数引擎e
    default_random_engine e;
public:
    //构造
    数组加强的哈希表(int capacity);
    //put
    void Put(K _Key,V _Value);
    //get
    V Get(K _Key);
    //remove
    void Remove(K _Key);
    //Random
    V Random();
};


#endif //DATAANDALOGORITHM_数组加强的哈希表_H