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

    int len = 1;
    vector<int> dp;
    dp.push_back(arr[0]);

    for(int i = 1;i<n;i++){
        if(arr[i] > dp.back()){
            len++;
            dp.push_back(arr[i]);
        }
        else{
            int idx = lower_bound(dp.begin(),dp.end(),arr[i]) - dp.begin();
            dp[idx] = arr[i];
        }
    } 

    cout<<len<<endl;
    
    return 0; 
}

// TC : O(n log n)
// SC : O(n)