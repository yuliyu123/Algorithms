//
// Created by looperX on 2019-10-19.
//
#include "Common.h"
#include "Util.h"
#include "leetcode/CountOfOne.h"
#include "leetcode/LinkedList.h"
#include "swordToOffer/StackToQueue.h"
#include "swordToOffer/ClockWisePrint.h"
#include "swordToOffer/BinaryTree.h"
#include "swordToOffer/LenMoreHalf.h"
#include "swordToOffer/MaxestSubArr.h"


using namespace std;

int main() {
    unsigned int LEN = sizeof(Node);
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

//    printf("%d\n", head->data);

    list->traverse(head);

//    std::cout << "start reverseRecursive" << std::endl;
//    Node* reverseNode = list->reverseRecursive(head);
//    list->traverse(reverseNode);

    Node* newNode;
    Node* newLinkAfterAdd = list->addNode(head, 7, 1);
    list->traverse(newLinkAfterAdd);
    Node* newLinkAfterDel = list->delNode(newLinkAfterAdd, node_03);
    list->traverse(newLinkAfterDel);
    delete head;
}

