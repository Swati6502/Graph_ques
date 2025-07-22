#include<iostream>
#include<unordered_map>
#include<queue>
#include <list>

using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here

    unordered_map<int,vector<int>> adj;

    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);    
    }

    unordered_map<int,bool> visited;
    unordered_map<int,int>parent;
    queue<int>q;
    vector<int>ans;
    
    visited[s]=true;
    parent[s] = -1;
    q.push(s);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour:adj[front]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }

    }

    int currentnode = t;
    ans.push_back(currentnode);
    while(currentnode != s){
        currentnode = parent[currentnode];
        ans.push_back(currentnode);
    }

    reverse(ans.begin(),ans.end());
    return ans;
	
}