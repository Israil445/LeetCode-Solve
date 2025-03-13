#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        vector<vector<int>> adjList;
        vector<int> inDegree;
        queue<int> q;
    
        bool bfs(int numCourses){
            int cnt = 0;
    
            while(!q.empty()){
                int node = q.front();
                q.pop();
                cnt++;
    
                for(auto v:adjList[node]){
                    inDegree[v]--;
                    if(inDegree[v]==0){
                        q.push(v);
                    }
                }
    
    
            }
    
            return (numCourses==cnt);
    
        }
    
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            adjList = vector<vector<int>>(numCourses);
            inDegree = vector<int>(numCourses, 0);
          
    
            for(int i=0;i<prerequisites.size();i++){
                adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }
    
            //compute inDegree
            for(int u=0;u<numCourses;u++){
                for(auto& v:adjList[u]){
                    inDegree[v]++;
                }
            }
    
            // push all the node into queue with indegree 0
            for(int i=0;i<numCourses;i++){
                if(inDegree[i]==0) q.push(i);
            }
    
            //process the node using bfs
            bool ans = bfs(numCourses);
    
            return ans;
    
        }
    };