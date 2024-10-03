#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> dp(n+1,1e9);
    dp[0] = 0;
    
    for(int i=1;i<=n;i++){
        int temp = i;
        while(temp > 0){
            if(temp % 10 != 0){
                dp[i] = min(dp[i],dp[i - (temp % 10)] + 1);
            }
            temp /= 10;
        }
    }

    cout<<dp[n]<<endl;
    
    return 0;
}
