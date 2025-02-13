#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* oddNode = head;
        ListNode* evenNode = head->next;
        ListNode* evenNodeHead = evenNode;

        while(evenNode && evenNode->next){
            oddNode->next = evenNode->next;
            oddNode = oddNode->next;

            evenNode->next = oddNode->next;
            evenNode = evenNode->next;
        }

        oddNode->next = evenNodeHead;
     
        return head;

    }
};

void printList(ListNode* head){
    ListNode* temp = head;
    while(temp){
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "original list: ";
    printList(head);

    Solution sol;
    head = sol.oddEvenList(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}