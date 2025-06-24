  #include<iostream>
  #include<unordered_map>
  #include<queue>
  #include <list>

  using namespace std;

//   only function

void bfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,vector<int>&ans, int node){

// bfs =  check node and then its adjacent nodes
// use queue because easily push from back and pop from front
     queue<int>q;

// pushing first node to queue
     q.push(node);

    //  make it true in visited 
     visited[node] = true;

    //  travers till the time queue is not empty
     while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

// check its all adjacent pairs
        for (auto i:adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i] =  true;
            }
        }
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
        // checking only for the edge which is not travers
        if(!visited[i]){
            bfs(adj,visited,ans,i);
        }
    }

    return ans;
    
}