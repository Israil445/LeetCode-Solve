#include<bits/stdc++.h>
using namespace std;


class Solution {
    private:
    vector<vector<bool>> visited;
    map<pair<int, int>, int> dist;
    int fresh_oranges = 0;
    
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    
    bool valid(int x, int y, vector<vector<int>>& grid) {
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && 
            !visited[x][y] && grid[x][y] != 0) { 
            return true;
        }
        return false;
    }
    
    void bfs(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
    
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) { 
                    visited[i][j] = true;
                    q.push({i, j});
                    dist[{i, j}] = 0;
                }
                if(grid[i][j]==1) fresh_oranges++;
            }
        }
    
        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
    
            for (int i = 0; i < 4; i++) {
                int next_x = node.first + dx[i];
                int next_y = node.second + dy[i];
    
                if (valid(next_x, next_y, grid)) {
                    visited[next_x][next_y] = true;
                    dist[{next_x, next_y}] = dist[{node.first, node.second}] + 1;
                    q.push({next_x, next_y});
                }
            }
        }
    }    
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
            bfs(grid);
            int ans = 0;
            int check_oranges = 0;
    
            for(auto& it:dist){
                if(grid[it.first.first][it.first.second]==1) check_oranges++;
                ans = max(ans, it.second);
            }
    
            if(check_oranges == fresh_oranges) return ans;
            return -1;
    
        }
    };


int main(){
    
    return 0;
}