#include "ListNode.h"

using namespace std;

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;       
    }
    return prev; 
}

int main(){
    ListNode* head = initByRandomNum(5);
    printList(head);
    ListNode* newhead = reverseList(head);
    printList(newhead);
    deleteList(head);
    return 0;
}