#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;

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

    vector<int> dist(n+1,INT_MAX);
    vector<int> parent(n+1);

    queue<int> q;
    q.push(1);

    dist[1] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int it:adj[node]){
            if(dist[it] == INT_MAX){
                dist[it] = dist[node] + 1;
                parent[it] = node;
                q.push(it);
            }
        }
    }
    
    if(dist[n] == INT_MAX)
        cout<<"IMPOSSIBLE"<<endl;

    else{
        cout<<dist[n] + 1<<endl;
        vector<int> temp;
        int x = n;
    
        while(x != 1){
            temp.push_back(x);
            x = parent[x];
        }

        temp.push_back(1);
        reverse(temp.begin(),temp.end());
    
        for(int i:temp)
            cout<<i<<" ";
    }
        
    return 0;
}