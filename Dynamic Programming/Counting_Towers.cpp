#include<bits/stdc++.h>
using namespace std; 

const int mod = 1e9 + 7;
const int maxi = 1e7;
long long dp[maxi][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    dp[1][1] = 1;
    dp[1][2] = 1;

    for(long long i=2;i<maxi;i++){
        dp[i][1] = ((dp[i-1][1] * 4) % mod + dp[i-1][2]) % mod;
        dp[i][2] = (dp[i-1][1] + (dp[i-1][2] * 2) % mod) % mod;
    }

    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;

        cout<<(dp[n][1] + dp[n][2]) % mod<<endl;
    }

    return 0; 
}
