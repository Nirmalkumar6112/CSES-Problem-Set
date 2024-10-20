#include<bits/stdc++.h>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a,b;
    cin>>a>>b;

    vector<vector<int>> dp(a+1,vector<int>(b+1,1e6));

    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }

            // Vertical Cut
            for(int v=1;v<=j-1;v++){
                dp[i][j] = min(dp[i][j],dp[i][v] + dp[i][j-v] + 1);
            }

            // Horizontal Cut
            for(int h=1;h<=i-1;h++){
                dp[i][j] = min(dp[i][j],dp[h][j] + dp[i-h][j] + 1);
            }
        }
    }

    cout<<dp[a][b]<<endl;

    return 0; 
}