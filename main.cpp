#include <iostream>
#include <climits>
#include <functional>
#include <vector>
#include <algorithm>
#include "leetcode/CountOfOne.h"
#include "leetcode/LinkedList.h"

#define var int;
#define print_var(var) printf("%d\n", var);

using namespace std;

typedef std::function<void(int)> Callback;

template<typename T>
T funcTest(int i, int i1);

template <typename T>
void printFunc(T arg)
{
    std::cout << arg << std::endl;
}

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
    unsigned int LEN = sizeof(Node);
    print_var(LEN);
    LinkedList* list = new LinkedList;
    Node* head = new Node;
    Node* node_01 = new Node;
    Node* node_02 = new Node;
    Node* node_03 = new Node;
    Node* node_04 = new Node;
    head->data = 0;
    node_01->data = 1;
    node_02->data = 2;
    node_03->data = 3;
    node_04->data = 4;
    head->nextNode = node_01;
    node_01->nextNode = node_02;
    node_02->nextNode = node_03;
    node_03->nextNode = node_04;
    node_04->nextNode = nullptr;

    printf("%d\n", head->data);
    list->traverse(head);

    list->reverse(head);
    list->traverse(head);
    delete head;
    return 0;
}
