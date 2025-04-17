#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode* next);
};

ListNode* initByForLoop(int n);
ListNode* initByNode();
ListNode* initByRandomNum(int n);
void printList(ListNode* head);
void deleteList(ListNode* head);

#endif 