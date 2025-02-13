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
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;

        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }

        int cnt = st.size()/2;
        int ans = INT_MIN;
        temp = head;

        while(cnt--){
            int sum = (temp->val)+st.top();
            temp = temp->next;
            st.pop();
            ans = max(ans, sum);
        }

        return ans;
    }
};