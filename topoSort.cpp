#include<bits/stdc++.h>
using namespace std;

// BFS approach (Kahn's algorithm)
vector<int> topoSort(int V , vector<int> adj[]){
        vector<int> ind(V, 0);
        vector<int> ans;
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                ind[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(ind[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int f = q.front();
            q.pop();
            ans.push_back(f);
            
            for(auto it: adj[f]){
                ind[it]--;
                if(ind[it]==0) q.push(it);
            }
        }
        return ans;
    }

// DFS Approach
void dfs(int start, stack<int>& s, vector<int>& vis, vector<int> adj[]){
	    vis[start] = 1;
        for(auto it: adj[start]){
            if(!vis[it]){
                dfs(it, s, vis, adj);
            }
        }
        s.push(start);
	}
int main(){
    // main function code for DFS approach
        int n; //no. of vertices
        vector<int> adj[10]; //adjacency list
	    vector<int> ans(n);
	    stack<int> s;
	    vector<int> vis(n, 0);
	    for(int i=0; i<n; i++){
	        if(!vis[i]) dfs(i, s, vis, adj);
	    }
	    int i=0;
	    while(!s.empty()){
	        int t = s.top();
	        s.pop();
	        ans[i] = t;
	        i++;
	    }
	    // return ans;
    return 0;
}