#include<iostream>
  #include<unordered_map>
  #include <vector>
  #include<list>

  using namespace std;


void dfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,vector<int>&ans, int node){

    ans.push_back(node);
    visited[node] = true;
    
    // for every connected node needs to do a recursive call
    for(auto i:adj[node]){
        dfs(adj,visited,ans,i);
    }

    
}
  vector<int>solve(int n, int u, int v, int direction){

    // adjacency list

    unordered_map<int,list<int>> adj;
    unordered_map<int,bool>visited;
    vector<int>ans;

    // create adjanceny list
    adj[u].push_back(v);

    if(direction == 0){
        adj[v].push_back(u);
    }

//    traverse all edges

    for(int i=0;i<n;i++){
        // checking only for the edge which is not traverse
        if(!visited[i]){ 
            dfs(adj,visited,ans,i);
        }
    }

    return ans;
    
}