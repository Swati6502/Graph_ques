  #include<iostream>
  #include<unordered_map>
  #include<queue>
  #include <list>

  using namespace std;

//   only function

bool isCycleBfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited, int src){

    unordered_map<int,int>parent;

    visited[src] = true;
    parent[src] = -1;

    queue<int>q;
    q.push(src);

    while(!q.empty()){

        int frontnode = q.front();
        q.pop();

        for(auto neighbour:adj[frontnode]){
            if(visited[neighbour] == true and neighbour != parent[frontnode]){
                return true;
            }
            else{
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontnode;
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
            bool ans =  isCycleBfs(adj,visited,i);

            if(ans == 1){
                return true;
            }
        }
    }

    return false;
    
}