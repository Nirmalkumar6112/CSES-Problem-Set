#include<bits/stdc++.h>
using namespace std; 

#define int long long int

void dfs(int node,int parent,int depth,vector<int> adj[],vector<int>& dp,vector<int>& res){
    res[1] += depth;

    for(auto& child : adj[node]){
        if(child != parent){
            dfs(child,node,depth+1,adj,dp,res);
            dp[node] += dp[child];
        }
    }
}

void dfs1(int node,int parent,vector<int> adj[],vector<int>& dp,vector<int>& res,int& n){
    for(auto child : adj[node]){
        if(child != parent){
            res[child] = res[node] + (n - (2*dp[child]));
            dfs1(child,node,adj,dp,res,n);
        }
    }
}

int32_t main(){
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

    vector<int> dp(n+1,1);
    vector<int> res(n+1,0);

    dfs(1,0,0,adj,dp,res);
    dfs1(1,0,adj,dp,res,n);
    
    for(int i=1;i<=n;i++){
        cout<<res[i]<<" ";
    }

    return 0; 
}

