#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        vector<int> pre(arr.size(), 0);
        pre[0] = arr[0];
        for(int i=1;i<arr.size();i++){
            pre[i] = pre[i-1] + arr[i];
        }

        int oddSum=0, evenSum=1;
        int result = 0;

        for(int i=0;i<pre.size();i++){
            if(pre[i]%2){
                oddSum++;
                result += evenSum;
                result %= MOD;
            }
            else{
                evenSum++;
                result += oddSum;
                result %= MOD;
            }
        }

        return result%MOD;
    }
};

    

int main(){
    Solution obj;
    vector<int> arr ={1,2,3,4,5,6,7};
    int ans = obj.numOfSubarrays(arr);

    cout << ans << endl;

    return 0;
}