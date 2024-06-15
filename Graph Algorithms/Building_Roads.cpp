#include<iostream>
#include<vector>
using namespace std;

void dfs(int node,vector<vector<int>>& adj,vector<bool>& vis){
    vis[node] = true;

    for(auto it : adj[node]){
        if(!vis[it])
            dfs(it,adj,vis);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n,false);
    vector<int> reqRoads;
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            reqRoads.push_back(i);
            dfs(i,adj,vis);
        }
    }

    cout<<reqRoads.size() - 1<<endl;
    
    for(int i=0;i<reqRoads.size() - 1;i++)
        cout<<reqRoads[i]<<" "<<reqRoads[i+1]<<endl;
    
    return 0;
}
