#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        int extract_pair(vector<int>&potions, long long target){
            int low = 0, high = potions.size()-1;
            int ans = potions.size();
    
            while(low<=high){
                int mid = (low+high)>>1;
                if(potions[mid]>=target) {
                    ans = mid;
                    high = mid - 1;
                }
                //else if(potions[mid]>target) high = mid - 1;
                else low = mid + 1;
            }
            return ans;
        }    
    public:
        vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
            sort(potions.begin(), potions.end());
            vector<int> ans;
            for(int i=0;i<spells.size();i++){
                long long target = success%spells[i] == 0 ? (success/spells[i]):(success/spells[i])+1;
                int count_pairs = extract_pair(potions,target);
               // cout << target << " " << count_pairs << endl;
                ans.push_back(potions.size()-count_pairs);
    
            }
    
            return ans;
        }
    };
    
    

int main(){

    return 0;
}