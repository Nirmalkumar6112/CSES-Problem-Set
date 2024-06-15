#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<long long,long long>>> adj(n+1);
    vector<long long> dist(n+1,LONG_MAX);
    dist[1] = 0;

    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;

        adj[u].push_back({v,wt});
    }

    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
    pq.push({0,1});

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        long long dis = it.first;
        long long node = it.second;

        if(dist[node] < dis)
            continue;
        
        for(auto cur : adj[node]){
            long long neighNode = cur.first;
            long long wt = cur.second;

            if(wt + dis < dist[neighNode]){
                dist[neighNode] = wt + dis;
                pq.push({dist[neighNode],neighNode});
            }           
        }
    }
    
    for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";

    return 0;
}