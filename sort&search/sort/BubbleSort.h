//
// Created by loohan on 2019/3/8.
//

#ifndef ALGORITHMMS_BUBBLESORT_H
#define ALGORITHMMS_BUBBLESORT_H
#include <iostream>
#include <climits>
#include <functional>
#include <vector>
#include <algorithm>

template <typename T, typename... Args>
void bubbleSort(T type, Args... args)
{
    std::vector<T> vec = {type, args...};
    auto func = [&](){
        for (int i = vec.size(); --i; i > 0)
        {
            for (int j = 0; j < i; ++j)
            {
                if (vec[j] <= vec[j + 1]) continue;
                std::swap(vec[j], vec[j+1]);
            }
        }
    };
    func();

    auto echo_func = [&](int i){
        std::cout << "i is: " << i << std::endl;
    };

    // lamada + filter擦除
    vec.erase(std::remove_if(vec.begin(), vec.end(), [&](T& type)
    {
        return type < 1;
    }), vec.end());
    std::for_each(vec.begin(), vec.end(), echo_func);
}

#endif //ALGORITHMMS_BUBBLESORT_H
