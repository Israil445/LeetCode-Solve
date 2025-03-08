#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = INT_MAX-1;
        sort(piles.begin(), piles.end());
        int ans = -1;

        while(low<=high){
            int mid = (low + high) >> 1;
            long long newH = 0;
            for(int i=0;i<piles.size();i++){
                newH += (piles[i]%mid==0 ? piles[i]/mid:(piles[i]/mid)+1);

            }
            if(newH <= h){
                ans = mid;
                high = mid - 1;

            }
            else low = mid + 1;

        }

        return ans;
    }
};

int main(){

    return 0;
}