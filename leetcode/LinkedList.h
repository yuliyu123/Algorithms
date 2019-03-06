//
// Created by loohan on 2019/3/6.
//

#ifndef ALGORITHMMS_LINKEDLIST_H
#define ALGORITHMMS_LINKEDLIST_H

#include <vector>
#include <iostream>

struct Node
{
    int data;
    Node* nextNode;
};

class LinkedList
{
public:
    int getData(Node* node)
    {
        return node->data;
    }

    void setData(Node* node)
    {
        node_->data = node->data;
    }

    void reverse(Node* head)
    {
        Node* pre;
        Node* cur;
        Node* next;

        while (head)
        {
            cur = head;
            next = head->nextNode;
            next->nextNode = cur;
//            cur->nextNode = nullptr;
            pre = cur;
            head = head->nextNode;
        }
    }

    void traverse(Node* node)
    {
        while (node)
        {
            std::cout << "this node data is: " << node->data << std::endl;
            node = node->nextNode;
        }
    }

    void addNode(Node* node)
    {

    }

    void delNode(Node* node)
    {

    }

    // 合并链表
    void merge(Node* node_01, Node* node_02)
    {

    }

    // 判断链表是否相交
    bool isIntersectLink(Node* node)
    {

    }

private:
    Node* node_;
};

#endif //ALGORITHMMS_LINKEDLIST_H
