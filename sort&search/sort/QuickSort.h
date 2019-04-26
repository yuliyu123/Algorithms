//
// Created by loohan on 2019/2/13.
//

#ifndef ALGORITHMMS_QUICKSORT_H
#define ALGORITHMMS_QUICKSORT_H

#endif //ALGORITHMMS_QUICKSORT_H

class QuickSort
{
public:
    int partition(int low, int high, int partition);
private:
};


// C++ 11
//template<typename T>
//std::list<T> sequential_quick_sort(std::list<T> input)
//{
//    if(input.empty())
//    {
//        return input;
//    }
//    std::list<T> result;
//    result.splice(result.begin(),input,input.begin());  // 1
//    T const& pivot=*result.begin();  // 2
//
//    auto divide_point=std::partition(input.begin(),input.end(),
//                                     [&](T const& t){return t<pivot;});  // 3
//
//    std::list<T> lower_part;
//    lower_part.splice(lower_part.end(),input,input.begin(),
//                      divide_point);  // 4
//    auto new_lower(
//            sequential_quick_sort(std::move(lower_part)));  // 5
//    auto new_higher(
//            sequential_quick_sort(std::move(input)));  // 6
//
//    result.splice(result.end(),new_higher);  // 7
//    result.splice(result.begin(),new_lower);  // 8
//    return result;
//}
//
//int main()
//{
//    std::cout << "max hardware_concurrency: " << std::thread::hardware_concurrency() << std::endl;
//    std::list<int> input = {3,2,1,8,9,0};
//    auto res = sequential_quick_sort(input);
//
//    for (auto& i : res) {
//        std::cout << i << std::endl;
//    }
//
//    std::cout << "main thread: " <<  std::this_thread::get_id() << std::endl;
//
//    return 0;
//}
