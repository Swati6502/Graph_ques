#include<iostream>
  #include<unordered_map>
  #include <vector>
  #include<list>
  #include<stack>
  #include<queue>

  using namespace std;

  // kahn's algorithm
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
//     adjacent list
   unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
//     unordered_map<int,bool> visited;  it will give tle so we will use vector at this place
// finding indegree of all the node and its adj node
    vector<int>indegree(v);
    
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    
    queue<int>q;
    
    for(int i=0;i<v;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int>ans;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        ans.push_back(front);
        
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    
    return ans;

    

}