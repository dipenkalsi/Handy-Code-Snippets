#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n+1 , 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i] = i;
        }
    }
    int findUltParent(int node){
        if(parent[node] == node) return node;
        else return parent[node] = findUltParent(parent[node]);
    }
    void unionBySize(int u , int v){
        int ulp_u = findUltParent(u);
        int ulp_v = findUltParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

    }
    void unionByRank(int u,int v){
        int ulp_u = findUltParent(u);
        int ulp_v = findUltParent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution
{
	public:
    static bool compare(pair<int , pair<int,int>> a , pair<int , pair<int,int>> b){
        return a.first<b.first;
    }
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        
        vector<int> vis(V, 0);
        
        int mstWt = 0;
        
        pq.push({0 , 0});
        
        while(!pq.empty()){
            auto it = pq.top();
            int node  = it.second;
            int wt = it.first;
            pq.pop();
            if(vis[node] == 1) continue;
            vis[node] = 1;
            mstWt += wt;
            for(auto it2:adj[node]){
                if(!vis[it2[0]]){
                    pq.push({it2[1] , it2[0]});
                }
            }
        }
        return mstWt;
    }
};
int main(){
    
    return 0;
}