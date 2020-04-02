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


// quickSort version 2
using namespace std;

int partition(vector<int>& data, int left, int right)
{
    int key = data[left];
    while (left < right)
    {
        while (left < right && key <= data[right])
        {
            --right;
        }
        if (left < right && key > data[right])
        {
            data[left++] = data[right];
        }

        while (left < right && data[left] <= key)
        {
            ++left;
        }
        if (left < right && data[left] > key)
        {
            data[right--] = data[left];
        }
    }
    data[left] = key;
    return left;
}

void quickSort(vector<int>& data, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int middle = 0;
    middle = partition(data, left, right);
    quickSort(data, left, middle - 1);
    quickSort(data, middle + 1, right);
}

int main()
{
    vector<int> v = {2, 3, 6, 1, 9};
    quickSort(v, 0, v.size() - 1);

    std::for_each(v.cbegin(), v.cend(), [](int data)
    {
        cout << "data: " << data << endl;
    });
}
