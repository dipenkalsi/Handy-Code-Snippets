#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       int ans = 0;
       vector<int> vis(V, 0);
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       pq.push({0, 0}); // stores {wt, node}
       // In case you have to return the MST edges, take a priority queue of the form {wt, {node, parent}}
       while(!pq.empty()){
           int wt = pq.top().first;
           int node = pq.top().second;
           pq.pop();
           
           if(vis[node]) continue;
           else vis[node] = 1;
           ans+=wt;
           
           for(auto it: adj[node]){
               if(!vis[it[0]]){
                   pq.push({it[1], it[0]});
               }
           }
       }
       return ans;
    }
};
int main(){
    
    return 0;
}