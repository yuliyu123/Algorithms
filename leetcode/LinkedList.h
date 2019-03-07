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

    Node* reverse(Node* head)
    {
        Node* pre = head;
        Node* cur = head->nextNode;
        Node* tmp;

        while (cur)
        {
            tmp = cur->nextNode;
            cur->nextNode = pre;
            pre = cur;
            cur = tmp;
        }
        head->nextNode = nullptr;
        return pre;
    }

    Node* reverseRecursive(Node* head)
    {
        Node* pre = head;
        if (head->nextNode == nullptr)
        {
            return head;
        }

        Node* reverseNode = reverseRecursive(head->nextNode);
        head->nextNode = head;
        head->nextNode = nullptr;
        return reverseNode;
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
