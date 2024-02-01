#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    int MOD = 1e9+7;
    cin>>n;
    
    vector<vector<int>> dp(n,vector<int>(n,-1));
    dp[0][0] = 1;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j] == '*')
                dp[i][j] = 0;
            
            else if(i == 0 && j == 0)
                dp[i][j] = 1;

            else{
                int up = 0,left = 0;
                if(i>0)
                    up = dp[i-1][j];
                if(j>0)
                    left = dp[i][j-1];
                
                dp[i][j] = (up+left) % MOD;
            }
        }
    }

    cout<<dp[n-1][n-1]<<endl;
    return 0;
}