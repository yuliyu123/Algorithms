//
// Created by loohan on 2019/3/6.
//

#ifndef ALGORITHMMS_REPLACEBLANK_H
#define ALGORITHMMS_REPLACEBLANK_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ReplaceBlank
{
public:
    string replace(string str)
    {
        string str_02;
        for (int j = 0; j < str.length(); ++j) {
            if (str[j] == ' ')
            {
                str_02.append("%20");
            } else {
                str_02.push_back(str[j]);
            }
        }
        return str_02;
    }
};

#endif //ALGORITHMMS_REPLACEBLANK_H
