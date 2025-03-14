#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int low = 0, high = matrix.size()*matrix[0].size() - 1;
    
            while(low <= high){
                int mid = (low + high) >> 1;
                int row = mid / matrix[0].size();
                int col = mid % matrix[0].size();
    
                if(matrix[row][col] == target) return true;
    
                else if(matrix[row][col] > target){
                    high = mid - 1;
                }
    
                else low = mid + 1;
            }
    
            return false;
        }
    };
    
    