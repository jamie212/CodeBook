#include "ListNode.h"
using namespace std;

ListNode* mergeRecusion(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2; 
    if (l2 == nullptr) return l1; 

    if (l1->val < l2->val) {
        l1->next = mergeRecusion(l1->next, l2);
        return l1; 
    } else {
        l2->next = mergeRecusion(l1, l2->next);
        return l2; 
    }
}

ListNode* mergeWithoutRecusion(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy; 

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next; 
        } else {
            tail->next = l2;
            l2 = l2->next; 
        }
        tail = tail->next; 
    }

    if (l1 != nullptr) {
        tail->next = l1; 
    } else {
        tail->next = l2; 
    }

    return dummy.next; 
}
int main() {
    ListNode* l1 = initByRandomNum(5);
    ListNode* l2 = initByRandomNum(5);
    printList(l1);
    printList(l2);

    ListNode* mergedRecursion = mergeRecusion(l1, l2);
    printList(mergedRecursion);

    // ListNode* mergedWithoutRecursion = mergeWithoutRecusion(l1, l2);
    // printList(mergedWithoutRecursion);

    deleteList(mergedRecursion);

    return 0;
}