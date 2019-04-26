//
// Created by loohan on 2019/4/18.
//

#ifndef ALGORITHMMS_BROKENCALC_H
#define ALGORITHMMS_BROKENCALC_H

#include <iostream>
#include <memory>
#include <string>
#include <functional>
#include <map>
#include <stdio.h>
#include <string.h>

using namespace std;

int brokenCalc(int X, int Y) {
    if (X > Y) return X - Y;
    if (X == Y) return 0;

    int step = 0;

    while (X < Y)
    {
        if (Y & 0x01) {
            ++Y;
            ++step;
        }
        if (!(Y & 0x01)) {
            Y /= 2;
            ++step;
        }
    }
    return step + X - Y;
}

int main()
{
    cout << brokenCalc(2, 3) <<endl;
    cout << brokenCalc(2, 4) <<endl;
    cout << brokenCalc(5, 8) <<endl;;
    cout << brokenCalc(3, 10) <<endl;
    cout << brokenCalc(1024, 1) <<endl;
    cout << brokenCalc(1, 1000000000) <<endl;
}

#endif //ALGORITHMMS_BROKENCALC_H
