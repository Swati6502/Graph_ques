  #include<iostream>
  #include<unordered_map>
  #include<queue>
  #include <list>

  using namespace std;

//   only function

void bfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,vector<int>&ans, int node){

     queue<int>q;

     q.push(node);
     visited[node] = true;
     while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto i:adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i = true];
            }
        }
     }
}
vector<int>solve(int n, int u, int v, int direction){

    // adjacency list

    unordered_map<int,list<int>> adj;
    unordered_map<int,bool>visited;
    vector<int>ans;

    adj[u].push_back(v);

    if(direction == 0){
        adj[v].push_back(u);
    }

   

    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(adj,visited,ans,i);
        }
    }
    
}