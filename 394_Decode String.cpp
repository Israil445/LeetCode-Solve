#include <bits/stdc++.h>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
       stack<int> nums;
       stack<string> st;

       for(int i=0;i<s.size();i++){
        if(s[i]=='['){
            st.push("[");
        }
        else if(isdigit(s[i])){
            int num = 0;
            while(isdigit(s[i])){
                num = num*10 + (s[i]-'0');
                i++;
            }
            i--;
            nums.push(num);
        }

        else if(s[i]==']'){
            string ns = "";
            while(!st.empty() && st.top()!="["){
                ns+=st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();

            int cycle = nums.top();
            nums.pop();
            string finalString = "";
            while(cycle--){
                finalString+=ns;
            }

            st.push(finalString);
        }
        else{
            string tmp(1, s[i]); 
            st.push(tmp);
        }
        
       }

       string ans = "";
       while(!st.empty()){
        ans += st.top();
        st.pop();
       }

       reverse(ans.begin(), ans.end());

       return ans;

    }
};

int main() {
    Solution solution;
    cout << solution.decodeString("3[a2[c]]") << endl;
    cout << solution.decodeString("2[abc]3[cd]ef") << endl; 
    return 0;
}
