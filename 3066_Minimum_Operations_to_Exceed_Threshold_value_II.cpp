#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long, vector<long long>, greater<long long>> pq;
            
            for (auto& it : nums) {
                pq.push(it);
            }

            int ans = 0;
            if (pq.top() >= k) return 0;
    
            while (pq.size() > 1) { 
                long long tp1 = pq.top();
                pq.pop();
                long long tp2 = pq.top();
                pq.pop();
    
                ans++;
                long long newVal = tp2 + tp1 * 2;  
                pq.push(newVal);
    
                if (pq.top() >= k) break; 
            }
    
            return ans;
        }
    };
    

int main() {
    Solution obj;
   vector<int> v = {97,73,5,78};
    int ans = obj.minOperations(v, 98);
    cout << ans << endl;

	return 0;
}