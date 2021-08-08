//
// Created by looperX on 7/26/21.
//

#ifndef ALGORITHMMS_CHANGTANG_H
#define ALGORITHMMS_CHANGTANG_H

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

#define MinABT 5
#define MaxABT 13

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

bool IsShunzi(vector<int> nCardID, int nCardCount)
{
    if (nCardCount < MinABT || nCardCount > MaxABT ||
        nCardID.size() != nCardCount || nCardID.empty()) return false;

    quickSort(nCardID, 0 , nCardCount - 1);
    for (int j = 0; j < nCardCount; ++j) {
        if (nCardID[j] == 52 || nCardID[j] == 53) {
            return false;
        }
    }
    return nCardID.back() - nCardID.front() == nCardCount - 1;
}

bool IsShunziEx(vector<int> nCardID, int nCardCount)
{
    if (nCardCount < MinABT || nCardCount > MaxABT ||
        nCardID.size() != nCardCount || nCardID.empty()) return false;

    quickSort(nCardID, 0 , nCardCount - 1);
    int i = nCardCount - 1;
    for (int j = nCardCount - 1; j > 0; --j) {
        if (nCardID[j] == 52 || nCardID[j] == 53) {
            --i; // i记录除大小王外最大值的下标
            continue;
        }
        if (j - 1 < 0 || nCardID[j] == nCardID[j-1]) return false;
    }
    return nCardID[i] - nCardID.front() < nCardCount;
}

// C++ 11 to compile it
int main(int argc, char* argv[])
{
    vector<int> nCardID = {9, 8, 3, 7, 6, 5, 2, 4};
    int nCardCount = 8;
    assert(IsShunzi(nCardID, nCardCount));
    assert(IsShunziEx(nCardID, nCardCount));

    nCardID = {0,1,3,4,53,6,8};
    nCardCount = 7;

    assert(!IsShunzi(nCardID, nCardCount));
    assert(!IsShunziEx(nCardID, nCardCount));

    nCardID = {4,5,6,7};
    nCardCount = 4;
    assert(!IsShunzi(nCardID, nCardCount));
    assert(!IsShunziEx(nCardID, nCardCount));

    nCardID = {52, 13, 11, 9, 53};
    nCardCount = 5;
    assert(!IsShunzi(nCardID, nCardCount));
    assert(IsShunziEx(nCardID, nCardCount));

    nCardID = {2, 3, 3, 4, 5, 6};
    nCardCount = 6;
    assert(!IsShunzi(nCardID, nCardCount));
    assert(!IsShunziEx(nCardID, nCardCount));

    return 0;
}

#endif //ALGORITHMMS_CHANGTANG_H
