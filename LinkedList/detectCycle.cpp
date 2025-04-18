#include "ListNode.h"
using namespace std;

bool hasCycle(ListNode* head) {
    if (head == nullptr) return false; 

    ListNode* slow = head;
    ListNode* fast = head; 

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next; 

        if (slow == fast) return true; 
    }

    return false; 
}

ListNode* findHeadOfCycle(ListNode* head) {
    if (head == nullptr) return nullptr; 

    ListNode* slow = head;
    ListNode* fast = head; 

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next; 

        if (slow == fast) {
            // Cycle detected
            // distance from head to cycle start = distance from slow to cycle start 
            slow = head; 
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next; 
            }
            return slow; 
        }
    }
    return nullptr; 
}

int main(){
    ListNode* head = initByForLoop(5);
    printList(head);
    cout << hasCycle(head) << endl;
    deleteList(head);

    ListNode* cycleHead = initByForLoop(5);
    ListNode* cycleNode = cycleHead->next->next; 
    ListNode* tail = cycleHead;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = cycleNode; // Create a cycle

    cout << hasCycle(cycleHead) << endl; 

    deleteList(cycleHead); 
    return 0;
}