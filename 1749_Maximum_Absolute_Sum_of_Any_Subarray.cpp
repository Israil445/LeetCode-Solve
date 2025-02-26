#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int mxSum = INT_MIN;
        int currentSum = 0;
        for(int i=0;i<nums.size();i++){
            currentSum += nums[i];
            if(currentSum>mxSum){
                mxSum = currentSum;
            }
            if(currentSum<0) currentSum = 0;
        }

        int mnSum = INT_MAX;
        currentSum = 0;
        for(int i=0;i<nums.size();i++){
            currentSum += nums[i];
            if(currentSum<mnSum) mnSum = currentSum;
            if(currentSum>0) currentSum = 0;
        }

        return max(abs(mnSum), mxSum);

    }
};
    
    

int main(){
    Solution sol;
    vector<int> nums = {1,-3,2,3,-4};
    int ans = sol.maxAbsoluteSum(nums);
    cout << ans << endl;

    return 0;
}