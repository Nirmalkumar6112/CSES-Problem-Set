#include<bits/stdc++.h>
using namespace std; 

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;

    ll sum = 0;

    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }   

    vector<vector<ll>> dp(n,vector<ll> (n,0));

    for(int l=n-1;l>=0;l--){
        for(int r = l;r<n;r++){
            if(l == r){
                dp[l][r] = arr[l];
            }
            else{
                dp[l][r] = max(arr[l] - dp[l+1][r],arr[r] - dp[l][r-1]);
            }
        }
    }

    cout<<(sum + dp[0][n-1]) / 2<<endl;
    
    return 0; 
}