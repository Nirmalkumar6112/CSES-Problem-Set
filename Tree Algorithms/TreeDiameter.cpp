
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
 
const int maxi = 2e5 + 1;
 
vector<int> adj[maxi];
int res = 0;
int last = 0;
 
void dfs(int u,int par,int dist){
    for(auto it : adj[u]){
        if( it != par)
            dfs(it,u,dist + 1);
    }
 
    if(dist > res){
        res = dist;
        last = u;
    }
}
 
int main(){
    int n;
    cin>>n;
 
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs(1,0,0);
    dfs(last,0,0);
 
    cout<<res<<endl;
    
    return 0;
}
