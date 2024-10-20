#include<bits/stdc++.h>
using namespace std; 

const int mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<int>> dp(n+1,vector<int> (m+1,0));

    //base case
    for(int i=1;i<=m;i++){
        if(arr[0] == 0 || arr[0] == i){
            dp[1][i] = 1;
        }
    }

    for(int i=2;i<=n;i++){
        for(int k=1;k<=m;k++){
            if(arr[i-1] != 0 && arr[i-1] !=k){
                dp[i][k] = 0;
                continue;
            }

            for(int prev = k-1;prev<=k+1;prev++){
                if(!(prev >= 1 && prev <= m)){
                    continue;
                }
                
                dp[i][k] = (dp[i][k] + dp[i-1][prev]) % mod;
            }
        }
    }
    
    int res = 0;
    for(int i=1;i<=m;i++){
        res = (res + dp[n][i]) % mod;
    }

    cout<<res<<endl;

    return 0; 
}

// TC : O(n*m)
// SC : O(n*m)