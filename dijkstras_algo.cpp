#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        pq.push({S, 0});
        while(!pq.empty()){
            auto f = pq.top();
            pq.pop();
            int node = f.first;
            int d = f.second;
            for(auto it: adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                if(d + edgeWeight < dist[adjNode]){
                    dist[adjNode] = d + edgeWeight;
                    pq.push({adjNode, d+edgeWeight});
                }
            }
        }
        return dist;
    }
    
int main(){
    
    return 0;
}