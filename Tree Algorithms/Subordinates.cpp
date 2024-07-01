
#include<iostream>
#include<vector>
using namespace std;
 
void dfs(int u,vector<int> adj[],vector<int>& dist){
    dist[u] = 1;
 
    for(auto it : adj[u]){
        dfs(it,adj,dist);
        dist[u] += dist[it];
    }
}
 
int main(){
    int n;
    cin>>n;
 
    vector<int> adj[n+1];
    vector<int> dist(n+1);
 
    for(int i=2;i<=n;i++){
        int parent;
        cin>>parent;
 
        adj[parent].push_back(i);
    }
 
    dfs(1,adj,dist);
 
    for(int i=1;i<=n;i++){
        cout<<dist[i] - 1<<" ";
    }
 
    return 0;
}
