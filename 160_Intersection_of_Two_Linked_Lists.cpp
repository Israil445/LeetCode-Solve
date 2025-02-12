#include <bits/stdc++.h>
using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode* pointerA = headA;
            ListNode* pointerB = headB;
    
            while(pointerA != pointerB){
                if(pointerA !=NULL) pointerA = pointerA->next;
                else if(pointerA==NULL) pointerA = headB;
    
                if(pointerB != NULL) pointerB = pointerB->next;
                else if(pointerB==NULL) pointerB = headA;
    
            }
    
            return pointerB;
    
        }
    };

int main(){

    return 0;
}    