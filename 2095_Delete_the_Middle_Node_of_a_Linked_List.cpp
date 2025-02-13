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
        ListNode* deleteMiddle(ListNode* head) {
            if(head->next == NULL) return NULL;
            int totalNode = 0;
            ListNode* temp = head;
            while(temp != NULL){
                totalNode++;
                temp = temp->next;
            }

            int midNode = totalNode/2;
            temp = head;
            midNode--;
            while(midNode--){
                temp = temp->next;
            }
            temp->next = temp->next->next;

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
    head->next->next->next->next->next = new ListNode(6);

    cout << "original list: ";
    printList(head);

    Solution sol;
    head = sol.deleteMiddle(head);

    cout << "Modified List: ";
    printList(head);

    return 0;
}