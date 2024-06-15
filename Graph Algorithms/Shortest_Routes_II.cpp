#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;

int main(){
    long long n,m,q;
    cin>>n>>m>>q;

    vector<vector<long long>> dist(n+1,vector<long long>(n+1,LONG_MAX));

    for(int i=0;i<m;i++){
        long long u,v,wt;
        cin>>u>>v>>wt;

        dist[u][v] = min(dist[u][v],wt);
        dist[v][u] = min(dist[v][u],wt);
    }

    for(int i=1;i<=n;i++)
        dist[i][i] = 0;

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k] == LONG_MAX || dist[k][j] == LONG_MAX)
                    continue;

                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;

        if(dist[a][b] >= LONG_MAX)
            cout<<-1<<endl;
        else    
            cout<<dist[a][b]<<endl;
    }

    return 0;
}

// Floyd_Warshall