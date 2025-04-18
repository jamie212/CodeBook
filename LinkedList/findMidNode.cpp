#include "ListNode.h"
using namespace std;

ListNode* findMidNode(ListNode* head) {
    if (head == nullptr) return nullptr; 

    ListNode* slow = head;
    ListNode* fast = head; 

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next; 
    }

    return slow; 
}

int main(){
    ListNode* head = initByForLoop(5);
    printList(head);
    ListNode* mid = findMidNode(head);
    cout << mid->val << endl;
    deleteList(head);
    return 0;
}