#include<iostream>
#include<unordered_map>
#include<stack>
#include <list>
#include<vector>
#include<queue>

using namespace std;


// using priority queue
vector<int> dijkstra(int v, vector<vector<int>> &edges, int src) {
        // Code here
        
        // adj list
        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int>dist(v,INT_MAX);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        dist[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto neighbour:adj[node]){
                int v = neighbour.first;
                int wt = neighbour.second;
                
                if(distance+wt < dist[v]){
                    dist[v] = distance+wt;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }