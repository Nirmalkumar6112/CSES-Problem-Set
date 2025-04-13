#include<bits/stdc++.h>
using namespace std; 

pair<int,int> bfs(int node,int n,vector<int> adj[]){
    queue<pair<int,int>> q;
    // {node,dist}
    q.push({node,0});

    vector<bool> vis(n+1,false);

    vis[node] = true;

    pair<int,int> u;

    while(!q.empty()){
        u = q.front();
        q.pop();

        for(auto& child : adj[u.first]){
            if(!vis[child]){
                q.push({child,u.second + 1});
                vis[child] = true;
            }
        }
    }

    return u;
}

void dfs(int node,int parent,int depth,int dpCol,vector<int> adj[],vector<vector<int>>& dp){
    dp[node][dpCol] = depth;

    for(auto& child : adj[node]){
        if(child != parent){
            dfs(child,node,depth + 1,dpCol,adj,dp);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> adj[n+1];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pair<int,int> a = bfs(1,n,adj);
    pair<int,int> b = bfs(a.first,n,adj);

    vector<vector<int>> dp(n+1,vector<int>(2,0));

    dfs(a.first,0,0,0,adj,dp);
    dfs(b.first,0,0,1,adj,dp);

    for(int i=1;i<=n;i++){
        cout<<max(dp[i][0],dp[i][1])<<" ";
    }
        
    return 0; 
}

