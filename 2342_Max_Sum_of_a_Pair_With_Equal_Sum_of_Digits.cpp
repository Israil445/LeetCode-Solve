#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        int digitSum(int n){
            if(n==0) return 0;
            return (n%10) + digitSum(n/10);
        }

    public:
        int maximumSum(vector<int>& nums) {
            map<int,priority_queue<int>> mp;

            for(int i=0;i<nums.size();i++){
                mp[digitSum(nums[i])].push(nums[i]);
            }

            int ans = -1;
            int x = -1, y=-1;
            for(auto it:mp){
                if(it.second.size()>=2) {
                    x=it.second.top();
                    it.second.pop();
                    y=it.second.top();
                    ans = max(ans, x+y);
                    
                }
            }
            return ans;
        }
    };

int main() {
    Solution obj;
   vector<int> v = {18,43,36,13,7};
    int ans = obj.maximumSum(v);
    cout << ans << endl;

	return 0;
}