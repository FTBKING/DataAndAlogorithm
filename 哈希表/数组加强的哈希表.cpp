//
// Created by lenovo on 2026/7/14.
//

#include "数组加强的哈希表.h"
#include <stdexcept>
#include <random>

template<class K, class V>
数组加强的哈希表<K, V>::数组加强的哈希表(int capacity) {
    this->capacity = capacity;
    //犯错点2：不能直接初始化v(capacity)，这个会生成占位符，不从0开始
    //应该用_arr.reserve(capacity)来预分配内存
    _arr.reserve(capacity);
}

template<class K, class V>
void 数组加强的哈希表<K, V>::Put(K _Key, V _Value) {
    //先判断是否存在
    if (_map.contains(_Key)) {
        _arr[_map[_Key]]._Value = _Value;
        return;
    }
    //不存在则新增
    //如果满了则抛异常
    //犯错点1：应该抛出runtime_error异常
    if (_arr.size() == capacity) throw std::runtime_error("哈希表满了");
    //先追加到数组后面
    _arr.push_back({_Key,_Value});
    //再把索引存到哈希表里
    _map[_Key] = _arr.size()-1;
    return;
}

template<class K, class V>
V 数组加强的哈希表<K, V>::Get(K _Key) {
    //获取，不存在则抛异常
    if (!_map.contains(_Key)) throw std::runtime_error("键不存在");
    return _arr[_map[_Key]]._Value;
}
//分文件编写，每个声明都得写template
template<class K, class V>
void 数组加强的哈希表<K, V>::Remove(K _Key) {
    //检查_map里是否存在key
    if (!_map.contains(_Key)) throw std::runtime_error("键不存在");
    //为了保证无空洞数组，需要和最后一位交换后再删除
    //拿到当前的Key的index
    int reindex = _map[_Key];
    //拿到最后位置的Key
    K lastKey = _arr.back()._Key;
    //最后位置和当前位置交换
    swap(_arr[reindex],_arr.back());
    //将最后位置的_Key的索引更新为rindex
    _map[lastKey] = reindex;
    //删除最后
    _arr.pop_back();
    //从哈希表中移除该Key
    _map.erase(_Key);
    return;
}

template<class K, class V>
V 数组加强的哈希表<K, V>::Random() {
    //获取随机位置的值
    if (_arr.empty()) throw std::runtime_error("哈希表为空");
    //遗忘点：怎么获取随机数？
    //uniform_int_distribution可以查手册
    uniform_int_distribution<int> dis(0,_arr.size()-1);
    //犯错点，需要初始化随机数引擎e
    int randomindex = dis(e);
    return _arr[randomindex]._Value;
}
