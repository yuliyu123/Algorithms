//
// Created by loohan on 2019/2/25.
//

#ifndef ALGORITHMMS_BINARYSORT_H
#define ALGORITHMMS_BINARYSORT_H

#include <vector>

class BinarySearch
{
public:
    int search(const std::vector<int> arr, int value)
    {
        int left = 0, right = arr.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left)/2;

            if (value < arr[mid])
            {
                right = mid - 1;
            }

            else if (value > arr[mid])
            {
                left = mid + 1;
            }

            else return mid;
        }
        return -1;
    }

private:

};

#endif //ALGORITHMMS_BINARYSORT_H
