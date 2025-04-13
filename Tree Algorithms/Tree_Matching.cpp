#include<bits/stdc++.h>
using namespace std; 

void dfs(int node,int par,vector<bool>& vis,vector<int> adj[],int& res){
    for(auto it : adj[node]){
        if(it != par){
            dfs(it,node,vis,adj,res);

            if(!vis[it] && !vis[node]){
                res++;
                vis[it] = true;
                vis[node] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> adj[n+1];

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }  

    vector<bool> vis(n+1,false);
    int res = 0;

    dfs(1,0,vis,adj,res);

    cout<<res;

    return 0; 
}
