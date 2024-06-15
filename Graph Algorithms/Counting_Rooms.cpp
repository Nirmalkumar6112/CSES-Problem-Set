#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void dfs(int r,int c,vector<vector<char> >& grid,vector<vector<int>>& vis,int n,int m){
    vis[r][c] = 1;
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};

    for(int i=0;i<4;i++){
        int newR = r + dr[i];
        int newC = c + dc[i];

        if(newR >= 0 && newR < n && newC >= 0 && newC < m && grid[newR][newC] == '.' && !vis[newR][newC]){
            vis[newR][newC] = 1;
            dfs(newR,newC,grid,vis,n,m);
        }
    }
}

int noOfRooms(vector<vector<char> >& grid,int n,int m){
    vector<vector<int>> vis(n,vector<int>(m,0));
    int res = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j] == '.'){
                res++;
                dfs(i,j,grid,vis,n,m);
            }
        }
    }

    return res;   
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<char> > grid(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    }

    cout<<noOfRooms(grid,n,m)<<endl;

    return 0;
}
