#include "ListNode.h"
using namespace std;

ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head; 

    // Find the middle of the list
    ListNode* slow = head;
    ListNode* fast = head; 
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next; 
    }

    // Split the list into two halves
    ListNode* secondHalf = slow->next;
    slow->next = nullptr; 

    // Sort each half recursively
    ListNode* left = sortList(head);
    ListNode* right = sortList(secondHalf);

    // Merge the sorted halves
    return mergeRecusion(left, right); 
}

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

int main() {
    ListNode* head = initByRandomNum(5);
    printList(head);
    ListNode* sortedHead = sortList(head);
    printList(sortedHead);
    deleteList(sortedHead);
    return 0;
}