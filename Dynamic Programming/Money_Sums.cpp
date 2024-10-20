#include<bits/stdc++.h>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int maxi = accumulate(arr.begin(),arr.end(),0);
    
    vector<vector<bool>> dp(n+1,vector<bool>(maxi+1,false));
    dp[0][0] = true;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=maxi;j++){
            dp[i][j] = dp[i-1][j];
            int remains = j - arr[i-1];

            if(remains >= 0 && dp[i-1][remains]){
                dp[i][j] = true;
            }
        }
    }

    vector<int> moneySums;
    for(int i=1;i<=maxi;i++){
        if(dp[n][i]){
            moneySums.push_back(i);
        }
    }

    cout<<moneySums.size()<<endl;
    for(auto i : moneySums){
        cout<<i<<" ";
    }
    
    return 0; 
}