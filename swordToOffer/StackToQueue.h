//
// Created by loohan on 2019/3/8.
//

#ifndef ALGORITHMMS_STACKTOQUEUE_H
#define ALGORITHMMS_STACKTOQUEUE_H

#include <stack>
#include <vector>

using namespace std;

stack<int> stack1, stack2;

void convertToQueue(const vector<int>& vec)
{
    int len = vec.size();
    if (!len)
    {
        return;
    }
    for (auto& value : vec)
    {
        stack1.push(value);
    }

    for (int i = 0; i < len; ++i)
    {
        stack2.push(stack1.top());
        stack1.pop();
    }

    for (int i = 0; i < len; ++i)
    {
        std::cout << "value is: " << stack2.top() << std::endl;
        stack2.pop();
    }
}

//int main() {
//    vector<int> input = {1, 2, 3, 4, 5};
//    convertToQueue(input);
//}

#endif //ALGORITHMMS_STACKTOQUEUE_H
