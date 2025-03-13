#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
        vector<vector<int>> adjList;
        vector<int> inDegree;
        queue<int> q;
        vector<int> topo_sort;
    
        void bfs(int numCourses){
            int cnt = 0;
            while(!q.empty()){
                int node = q.front();
                topo_sort.push_back(node);
                q.pop();
                cnt++;
    
                for(auto v:adjList[node]){
                    inDegree[v]--;
                    if(inDegree[v]==0){
                        q.push(v);
                    }
                }
            }
    
            if(cnt != numCourses) topo_sort.clear();
        }    
    public:
    
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
           adjList = vector<vector<int>>(numCourses);
           inDegree = vector<int>(numCourses, 0);
    
            //making adjacent list
           for(int i=0;i<prerequisites.size();i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
           }
    
            //compute inDegree
            for(int u=0;u<numCourses;u++){
                for(auto& v:adjList[u]){
                    inDegree[v]++;
                }
            }
    
            //push all the node with queue with indegree 0 
            for(int i=0;i<numCourses;i++){
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
    
            //process the node using bfs
            bfs(numCourses);
    
            return topo_sort;
        }
    };