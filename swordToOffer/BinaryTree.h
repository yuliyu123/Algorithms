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

BinaryNode* rootNode = new BinaryNode;
BinaryNode* left_01 = new BinaryNode;
BinaryNode* right_01 = new BinaryNode;
BinaryNode* left_02 = new BinaryNode;
BinaryNode* right_02 = new BinaryNode;
BinaryNode* left_03 = new BinaryNode;
BinaryNode* right_03 = new BinaryNode;

void contruct(BinaryNode* root)
{
    root->data = 1;
    left_01->data = 2;
    right_01->data = 3;
    left_02->data = 4;
    right_02->data = 5;
    left_03->data = 6;
    right_03->data = 7;

    root->leftTree = left_01;
    root->rightTree = right_01;
    left_01->leftTree = left_02;
    left_01->rightTree = right_02;
    right_01->leftTree = left_02;
    right_01->rightTree = right_02;
    left_02->leftTree = nullptr;
    left_02->rightTree = nullptr;
    right_02->leftTree = nullptr;
    right_02->rightTree = nullptr;
    left_03->leftTree = nullptr;
    left_03->rightTree = nullptr;
    right_03->leftTree = nullptr;
    right_03->rightTree = nullptr;
}

void printBinTree(BinaryNode* root)
{
    std::cout << "this tree data is: " << root->data << std::endl;
    if (root->leftTree) {
//        std::cout << "this tree left child data is: " << root->leftTree->data << std::endl;
        printBinTree(root->leftTree);
    }
    if (root->rightTree)
    {
//        std::cout << "this tree left child data is: " << root->rightTree->data << std::endl;
        printBinTree(root->rightTree);
    }
}

#endif //ALGORITHMMS_BINARYTREE_H
