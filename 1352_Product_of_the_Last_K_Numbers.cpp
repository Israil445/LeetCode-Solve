#include<bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
private:
    vector<int> pre;
public:
    ProductOfNumbers() {
        pre.push_back(1);
    }
    
    void add(int num) {
        if(num!=0){
            pre.push_back(pre.back()*num);

        }
        else{
            pre.clear();
            pre.push_back(1);
        }
    }
    
    int getProduct(int k) {
        if(k>=pre.size()) return 0;
        return pre.back()/pre[pre.size()-k-1];
    }
};
    

int main(){


    return 0;
}

