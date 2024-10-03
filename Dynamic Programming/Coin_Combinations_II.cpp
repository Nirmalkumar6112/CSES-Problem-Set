#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,x;
    cin>>n>>x;

    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    vector<vector<int>> dp(n+1,vector<int> (x+1));

    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }

    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=x;j++){
            int notTake = dp[i+1][j];

            int take = 0;
            if(coins[i] <= j){
                take = dp[i][j - coins[i]];
            }

            dp[i][j] = (take + notTake) % mod;
        }
    }

    cout<<dp[0][x]<<endl;

    return 0;
}
