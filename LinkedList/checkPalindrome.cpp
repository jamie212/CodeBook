#include "ListNode.h"
using namespace std;

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true; 

    // Find the middle of the list
    ListNode* slow = head;
    ListNode* fast = head; 
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next; 
    }

    // Reverse the second half of the list
    ListNode* prev = nullptr;
    ListNode* current = slow;

    while (current != nullptr) {
        ListNode* next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;       
    }

    // Compare the two list
    ListNode* firstHalf = head;
    ListNode* secondHalf = prev; 

    while (secondHalf != nullptr) {
        if (firstHalf->val != secondHalf->val) return false; 
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next; 
    }

    return true; 
}