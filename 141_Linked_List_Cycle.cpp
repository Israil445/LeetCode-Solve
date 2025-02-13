#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        //no cycle if list is empty or has only one node
        if(!head || !head->next) return false;

        ListNode *slow = head;
        ListNode *fast = head;
        //Floyd's cycle detection algorithm(Tortoise and Hare algorithm)
        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;//slow move 1 unit
            fast = fast->next->next;//fast move 2 unit
            if(slow==fast) return true;//cycle detected
        }

        return false;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head->next; 

    Solution sol;
    if (sol.hasCycle(head)) 
        cout << "Cycle detected!" << endl;
    else 
        cout << "No cycle detected!" << endl;

    return 0;
}
