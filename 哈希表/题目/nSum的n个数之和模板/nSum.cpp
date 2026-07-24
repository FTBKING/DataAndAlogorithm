//
// Created by lenovo on 2026/7/17.
//

#include "nSum.h"

//犯错：不能返回引用，除非是全局的，方法执行完局部变量result会自动被回收
vector<vector<int>> nSum::nSumRecursive(vector<int>& _nums,int start,int n, long long target) {
    //犯错：必须是排好序的数组
    //获取好数组大小，等待复用
    int sz = _nums.size();
    //问题：结果数组用啥装的？
    //vector嵌套vector，可以直接用二维数组的方式获取
    vector<vector<int>> result;
    //判断当前要求的n是否合理：若n小于2 || 数组大小小于n就停止
    //题目要求返回空的结果
    if (n<2 || sz < n) return result;
    //如果递归降维到2了，就可以用左右指针模板解决2Sum
    if (n==2) {
        //1.准备好高低指针
        //nSum里，lo应该从start开始
        int lo = start; int hi = sz-1;
        //2.只要lohi指针不相撞
        while (lo<hi) {
            //准备好lo_v,hi_v,两个的总和sum
            int lo_v = _nums[lo]; int hi_v = _nums[hi];
            //犯错：涉及到和与差计算的必须用long long，输入条件过大会溢出
            long long sum = (long long)lo_v+hi_v;
            //1.如果总和大于target
            if (sum>target) {
                //总和大->让hi指针左移变小，并且左移后不能重复
                while (lo<hi && _nums[hi] == hi_v) hi--;
            }else if(sum<target) { //2.如果总和小于target
                //总和小->lo指针右移变大,并且右移后不能重复
                while (lo<hi && _nums[lo] == lo_v) lo++;
            }else { //3.如果总和等于target
                //找到了，存到结果数组里
                //直接pushback一组结果进去
                result.push_back({lo_v,hi_v});
                //移动高低指针，去重
                while (lo<hi && _nums[hi] == hi_v) hi--;
                while (lo<hi && _nums[lo] == lo_v) lo++;
            }
        }
    }else { //如果不是二维，就利用递归降低维度，模板待学习
        //从start开始遍历数组所有元素
        for (int i = start;i<sz;i++) {
            //1.递归调用自己
            //求n个数的和，就等于求n-1个数的和 = n个数的和 - 第n个数
            vector<vector<int>> sub = nSumRecursive(_nums,i+1,n-1,target - _nums[i]);
            //得到子结果后，第n个数pushback进去就是完整结果，然后把结果数组pushback到result中
            for (vector<int>& e : sub) { //优化：这里可以引用优化，防止又复制一次
                e.push_back(_nums[i]);
                result.push_back(e);
            }
            //向下一个数字走之前需要去重,若下一位和当前数字相同，则向后移动
            //问题：为啥需要去重？
            //如果不去重，就会出现重复的结果数组，不符合要求
            //犯错:i必须小于sz-1，如果到最后一位还去取i+1，就会发生数组越界
            while (i<sz-1 && _nums[i+1] == _nums[i]) i++;
        }
    }
    return result;
}

vector<int> nSum::twoSum(vector<int> &nums, int target) {
    //hash表
    unordered_map<int,int> _valueToIndex;
    for (int i =0;i<nums.size();i++) {
        //1.计算出这个数字需要和另外哪一个数字组合
        //不要忘记防止溢出
        long long need = (long long)target - nums[i];
        //2.如果之前添加到过hash表里，直接返回
        if (_valueToIndex.count(need)) {
            return {_valueToIndex[need],i};
        }
        //3.如果没添加过就添加
        _valueToIndex[nums[i]] = i;
    }
    //没找到要返回空兜底
    return {};
}
