//
// Created by looperX on 8/8/21.
//

#ifndef ALGORITHMMS_BIG_SMALL_ENDIAN_H
#define ALGORITHMMS_BIG_SMALL_ENDIAN_H


#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

#define MinABT 5
#define MaxABT 13

using namespace std;


// C++ 11 to compile it
int main(int argc, char* argv[])
{
    int i=1;   // 0x01
    char *p=(char *)&i;
    if(*p == 1)     // 低位字节在低地址
        printf("小端模式");
    else // (*p == 0)  // 高位字节在低地址
        printf("大端模式");

    return 0;
}


#endif //ALGORITHMMS_BIG_SMALL_ENDIAN_H
