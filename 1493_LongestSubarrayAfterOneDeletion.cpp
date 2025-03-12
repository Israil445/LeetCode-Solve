#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool AllOne(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) return false;
        }
        return true;
    }    
public:
    int longestSubarray(vector<int>& nums) {
        if(AllOne(nums)) return nums.size()-1;
        pair<int,int> zero_cnt = {0,0};
        int subarray = 0;
        int ans = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) {
                zero_cnt.first++;
               if(zero_cnt.first != 2) zero_cnt.second = i;
              
            }
            if(zero_cnt.first!=2){
                subarray++;
               
            }
            if(zero_cnt.first==2){
                ans = max(ans, subarray-1);
                subarray = i - zero_cnt.second;
                zero_cnt.second = i;
                zero_cnt.first = 1;
            }
        }
        ans = max(ans, subarray-1);
        return ans;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {0,1,1,1,0,1,1,0,1};
    int ans = sol.longestSubarray(nums);
    cout << ans << endl;

    return 0;
}