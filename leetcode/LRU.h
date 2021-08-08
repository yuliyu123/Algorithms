//
// Created by loohan on 2019/4/26.
//

#ifndef ALGORITHMMS_LRU_H
#define ALGORITHMMS_LRU_H

#include <iostream>
#include <memory>
#include <string>
#include <functional>
#include <map>
#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

class LRUCache
{
    struct Node
    {
        int key;
        int value;
    };

private:
    int capacity_;
    list<Node> cacheList_;
    unordered_map<int, list<Node>::iterator> itemMap_;

public:
    LRUCache(int capacity)
    {
        capacity_ = capacity;
    }

    int get(int key)
    {
        if (cacheList_.size() == 0)
        {
            return -1;
        }

        if (itemMap_.find(key) == itemMap_.end()) // can't find
        {
            return -1;
        } else {
            cacheList_.erase(itemMap_[key]);
            Node node;
            node.key = key;
            node.value = itemMap_[key]->value;
            cacheList_.push_front(node);
            itemMap_[key] = cacheList_.begin();
        }
        return cacheList_.begin()->value;
    }

    void put(int key, int value)
    {
        if (cacheList_.size() == capacity_ and itemMap_.find(key) == itemMap_.end())  // is full and not found
        {
            itemMap_.erase(cacheList_.back().value);
            cacheList_.pop_back();
        }

        if (itemMap_.find(key) != itemMap_.end()) // inside cachelist
        {
            cacheList_.erase(itemMap_[key]);
            Node node;
            node.key = key;
            node.value = value;
            cacheList_.push_front(node);
            itemMap_[key] = cacheList_.begin();
            return;
        } else {
            Node node;
            node.key = key;
            node.value = value;
            cacheList_.push_front(node);
            itemMap_[key] = cacheList_.begin();
        }
    }
};

int main()
{
    cout << __cplusplus << endl;
    LRUCache* lru = new LRUCache(3);
    lru->put(1, 1);
    lru->put(2, 2);
    lru->put(3, 3);
    lru->put(4, 4);

    cout << lru->get(2) << endl;
    cout << lru->get(3) << endl;
    cout << lru->get(4) << endl;
    cout << lru->get(4) << endl;
    cout << lru->get(1) << endl;

    delete lru;
    return 0;
}



#endif //ALGORITHMMS_LRU_H
