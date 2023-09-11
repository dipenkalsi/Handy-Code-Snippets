#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool detect(int src, vector<int> adj[], vector<int>& vis, vector<int>& pathVis){
        vis[src] = 1;
        pathVis[src] = 1;
        
        for(auto it: adj[src]){
            if(!vis[it]){
                if(detect(it, adj, vis, pathVis)) return true;
            }
            else if(pathVis[it]) return true;
        }
        
        pathVis[src] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0), pathVis(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(detect(i, adj, vis, pathVis)) return true;
            }
        }
        return false;
    }
};
int main(){
    
    return 0;
}