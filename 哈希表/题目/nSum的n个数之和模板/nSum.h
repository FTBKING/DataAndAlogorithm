//
// Created by lenovo on 2026/7/17.
//

#ifndef DATAANDALOGORITHM_NSUM_H
#define DATAANDALOGORITHM_NSUM_H

#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class nSum {
private:
    //排好序的数组
    vector<int> _arr;
public:
    //输入一个数组，一个target
    //数组只能首地址传递
    //返回1个二维数组指针，可以嵌套两个vector当多维度数组
    vector<int> TwoSum(vector<int>& _nums,int target);


};


#endif //DATAANDALOGORITHM_NSUM_H