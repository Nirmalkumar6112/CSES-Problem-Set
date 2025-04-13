#include<bits/stdc++.h>
using namespace std; 

const int mod = 2 * (1e9 + 7);
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;

    long long sum = (n * (n+1)) / 2;

    if(sum % 2){
        cout<<0;
        return 0;
    }

    vector<ll> dp(sum + 1);
    dp[0] = 1;

    for(ll i=1;i<=n;i++){
        for(ll j=sum;j>0;j--){
            if(j - i >= 0){
                dp[j] = (dp[j] + dp[j - i]) % mod;
            }
        }
    }
    
    cout<<dp[sum/2]/2<<endl;

    return 0; 
}
