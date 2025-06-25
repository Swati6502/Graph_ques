  #include<iostream>
  #include<unordered_map>
  #include<queue>
  #include <list>

  using namespace std;

//   only function

bool isCycleDFS(int src,int parent,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited){

    visited[src]  = true;

    for(auto neighbour:adj[src]){
        if(!visited[neighbour]){
            bool isCyclePresent = isCycleDFS(neighbour,src,adj,visited);
            if(isCyclePresent){
                return true;
            }
            else if(neighbour != parent){
                return true;
            }
        }
    }

    
    return false;
}
bool solve(int n, int u, int v, int direction){

    // adjacency list

    unordered_map<int,list<int>> adj;
    unordered_map<int,bool>visited;
    

    // create adjanceny list
    adj[u].push_back(v);

    if(direction == 0){
        adj[v].push_back(u);
    }

//    traverse all edges

    for(int i=0;i<n;i++){
        // checking only for the edge which is not travers
        if(!visited[i]){
            bool ans =  isCycleDFS(i,-1,adj,visited);

            if(ans == 1){
                return true;
            }
        }
    }

    return false;
    
}