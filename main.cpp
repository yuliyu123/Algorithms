#include <iostream>
#include <climits>
#include <functional>
#include <vector>
#include <algorithm>
#include "leetcode/CountOfOne.h"

using namespace std;

typedef std::function<void(int)> Callback;

template<typename T>
T funcTest(int i, int i1);

void callback(int input)
{
    std::cout << "here is callback, input: " << input << std::endl;
}

void setCallBack(Callback cb, int i)
{
    cb(i);
    std::cout << "here is setCallBack" << std::endl;
    cb(++i);
}

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

int main()
{
    bubbleSort(0, 7, 3, 1, 2, 5, 2, 3, 14, 9);
//    bubbleSort(1.2, 0.1, 1.1, 5.4, 2.5, 5.3, 2.01, 3.14, 14.3, 9.8);
//    for (int i = 6; --i; i > 0) {
//        std::cout << i << std::endl;
//    }
    return 0;
}
