#include<iostream>
#include<unordered_map>
#include<stack>
#include <list>
#include<vector>

using namespace std;

    void topoSort(int node, vector<int> &visited, unordered_map<int, vector<pair<int,int>>> &adj, stack<int> &s){
        visited[node] = 1;
        
        for(auto neighbour : adj[node]){
            int v = neighbour.first;
            if(!visited[v]){
                topoSort(v, visited, adj, s);
            }
        }
        s.push(node);
    }
    vector<int> shortestPath(int v, int e, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int,int>>> adj;

        // Build adjacency list
        for(int i = 0; i < e; i++){
            int u = edges[i][0];
            int vv = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({vv, wt});
        }

        vector<int> visited(v, 0);  // ✅ FIXED
        stack<int> s;

        for(int i = 0; i < v; i++){
            if(!visited[i]){
                topoSort(i, visited, adj, s);
            }
        }

        vector<int> distance(v, INT_MAX);
        distance[0] = 0;

        while(!s.empty()){
            int node = s.top();
            s.pop();

            if(distance[node] != INT_MAX) {
                for(auto neighbour : adj[node]){
                    int v = neighbour.first;
                    int wt = neighbour.second;

                    if(distance[node] + wt < distance[v]){
                        distance[v] = distance[node] + wt;
                    }
                }
            }
            
        }
        for(auto &d : distance)
            if(d == INT_MAX)d = -1;

        return distance;
    }

    
