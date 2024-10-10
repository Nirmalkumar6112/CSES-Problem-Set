#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,amount;
    cin>>n>>amount;

    vector<int> price(n),pages(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }

    vector<vector<int>> dp(n,vector<int>(amount+1,0));

    for(int p=price[0];p<=amount;p++){
        dp[0][p] = pages[0];
    }

    for(int idx = 1;idx<n;idx++){
        for(int p=0;p<=amount;p++){
            int notTake = 0 + dp[idx-1][p];

            int take = INT_MIN;

            if(price[idx] <= p){
                take = pages[idx] + dp[idx-1][p - price[idx]];
            }
            dp[idx][p] = max(take,notTake);            
        }
    }

    cout<<dp[n-1][amount]<<endl;

    return 0;
}

// Tabulation