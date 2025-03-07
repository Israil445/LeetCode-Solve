#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPrime(int num){
        for(int i=2;i*i<=num;i++){
            if(num%i == 0) return false;
        }

        return true;
    }
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        for(int i=left;i<=right;i++){
            if(isPrime(i) && i!=1){
                primes.push_back(i);
            }
        }

        int a=-1,b=-1;
        int mn = INT_MAX;
    
        for(int i=1;i<primes.size();i++){
            if(primes[i]-primes[i-1] < mn){
                a = primes[i-1];
                b = primes[i];
                mn = primes[i]-primes[i-1];
            }
        }

        return {a,b};
    }
};
int main(){
    Solution sol;
    vector<int> ans = sol.closestPrimes(10,20);
    for(auto &it:ans){
        cout << it<< " ";
    }cout << endl;

    return 0;
}