//
// Created by looperX on 2019-10-19.
//
/*
 * 让数组中的奇数位于偶数之前
 * */
#include <memory>
#include <iostream>
#include <ostream>
#include <string>
#include <iterator>
#include <sstream>
#include <algorithm>

using namespace std;

// 判断是否是奇数
bool isOdd(int x)
{
    return x % 2 == 1;
}

int main()
{
    int arr[] = {1,2,4,5,7};
//    std::partition(arr, arr + 6, &isOdd); // 不能保持奇数的相对位置不变
    std::stable_partition(arr, arr + 6, &isOdd); // 保持相对位置不变
    // 重载输出迭代器的操作符
    std::copy(arr, arr + 6, std::ostream_iterator<int>(std::cout, ","));
}

