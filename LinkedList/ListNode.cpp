#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* initByForLoop(int n) {
    if (n <= 0) return nullptr; 

    ListNode* head = new ListNode(1); 
    ListNode* current = head;

    for (int i = 2; i <= n; i++) {
        current->next = new ListNode(i);
        current = current->next; 
    }

    return head; 
}

ListNode* initByNode(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    return head;
}

ListNode* initByRandomNum(int n){
    ListNode* head = new ListNode(rand() % 20);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(rand() % 20);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

void deleteList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr; 
    cout << "List deleted." << endl;
}