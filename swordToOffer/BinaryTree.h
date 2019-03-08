//
// Created by loohan on 2019/3/8.
//

#ifndef ALGORITHMMS_BINARYTREE_H
#define ALGORITHMMS_BINARYTREE_H

#include "Common.h"

struct BinaryNode
{
    int data;
    BinaryNode* leftTree;
    BinaryNode* rightTree;
};

BinaryNode* root = new BinaryNode;
void contruct()
{
    root->data = 1;
    std::cout << root->data << std::endl;
}

#endif //ALGORITHMMS_BINARYTREE_H
