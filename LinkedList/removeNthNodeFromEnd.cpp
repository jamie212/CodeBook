#include "ListNode.h"
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* helper = head;
    for(int i = 0; i <= n; i++){
        helper = helper->next;
    }
    ListNode* toDel = head;
    while(helper != nullptr){
        toDel = toDel->next;
        helper = helper->next;
    }
    toDel->next = toDel->next->next;
    return head;
}

int main(){
    ListNode* head = initByForLoop(5);
    printList(head);
    head = removeNthFromEnd(head, 2);
    printList(head);
    deleteList(head);
    return 0;
}