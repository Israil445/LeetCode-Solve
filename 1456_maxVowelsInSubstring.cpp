#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        return false;
    }

public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int cnt = 0;
        
        //first k-element vowels
        for(int i=0;i<k;i++){
            if(isVowel(s[i])) cnt++;
        }
        ans = max(ans, cnt);

        for(int i=k;i<s.size();i++){
            if(isVowel(s[i])) cnt++;
            if(isVowel(s[i-k])) cnt--;
            ans = max(ans, cnt);
        }

        return ans;
    }
};  
    

int main(){
    Solution sol;
    vector<int> nums = {1,-3,2,3,-4};
    int ans = sol.maxVowels("abciiidef",3);
    cout << ans << endl;

    return 0;
}