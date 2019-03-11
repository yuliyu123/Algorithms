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
        head->nextNode->nextNode = head;
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

    /*
     * linklist add and delete's complexity is O(1), but search is O(n)
     * */
    Node* addNode(Node* head, int i, int index)
    {
        std::cout << "linklist add node start" << std::endl;
        Node* newNode;
        newNode->data = i;
        if (index == 1) {
            newNode->nextNode = head;
            return newNode;
        }

        Node* tmp = head;
        for (int i = 1; i < index; i++)
        {
            tmp = tmp->nextNode;
        }
        newNode->nextNode = tmp->nextNode;
        tmp->nextNode = newNode;
        return head;
    }

    Node* delNode(Node* head, Node* toBeDeleted)
    {
        std::cout << "linklist del node start" << std::endl;
        if (!head or !toBeDeleted)
        {
            return nullptr;
        }

        Node* tmp = head;
        while (tmp)
        {
            if (tmp->nextNode == toBeDeleted)
            {
                tmp->nextNode = tmp->nextNode->nextNode;
                break;
            }
            tmp = tmp->nextNode;
        }
        return head;
    }

    // 合并链表
    Node* merge(Node* head_01, Node* head_02)
    {
        std::cout << "linklist del node start" << std::endl;
        if (!head_01 or !head_02) return nullptr;

        Node* newLink;
        while (head_01 and head_02)
        {
            if (head_01->data < head_02->data)
            {
                head_01->nextNode = head_02;
            } else
            {
                head_02->nextNode = head_01;
            }
            head_01 = head_01->nextNode;
            head_02 = head_02->nextNode;
        }

        while (head_01)
        {
            head_01->nextNode = head_01;
            head_01 = head_01->nextNode;
        }
        while (head_02)
        {
            head_02->nextNode = head_02;
            head_02 = head_02->nextNode;
        }
    }

    // 判断链表是否相交
    bool isIntersectLink(Node* node)
    {

    }

private:
    Node* node_;
};

//int main() {
//    unsigned int LEN = sizeof(Node);
//    print_var(LEN);
//    LinkedList* list = new LinkedList;
//    Node* head = new Node;
//    Node* node_01 = new Node;
//    Node* node_02 = new Node;
//    Node* node_03 = new Node;
//    Node* node_04 = new Node;
//    head->data = 0;
//    node_01->data = 1;
//    node_02->data = 2;
//    node_03->data = 3;
//    node_04->data = 4;
//    head->nextNode = node_01;
//    node_01->nextNode = node_02;
//    node_02->nextNode = node_03;
//    node_03->nextNode = node_04;
//    node_04->nextNode = nullptr;
//
//    printf("%d\n", head->data);
//    list->traverse(head);
//
//    std::cout << "start reverseRecursive" << std::endl;
//    Node* reverseNode = list->reverseRecursive(head);
//    list->traverse(reverseNode);
//
//    Node* newNode;
//    newNode->data = 6;
//    Node* newLink = list->addNode(head, 2, 22);
//    list->traverse(newLink);
//    delete head;
//}

#endif //ALGORITHMMS_LINKEDLIST_H
