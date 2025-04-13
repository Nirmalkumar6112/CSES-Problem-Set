#include<bits/stdc++.h>
using namespace std; 

#define ll long long

struct Project{
    ll start;
    ll end;
    ll profit;
};

bool cmp(Project a,Project b){
    return a.end < b.end;
}

ll binarySearch(vector<Project>& arr,int idx){
    ll low = 0;
    ll high = idx-1;

    while(low <= high){
        ll mid = (low + high) / 2;

        if(arr[mid].end < arr[idx].start){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return high;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin>>n;

    vector<Project> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].end>>arr[i].profit;
    }
    
    sort(arr.begin(),arr.end(),cmp);

    vector<ll> dp(n,0);
    dp[0] = arr[0].profit;

    for(int i=1;i<n;i++){
        ll take = arr[i].profit;

        ll idx = binarySearch(arr,i);

        if(idx != -1){
            take += dp[idx];
        }

        ll notTake = dp[i-1];

        dp[i] = max(take,notTake);
    }

    cout<<dp[n-1];
    
    return 0; 
}
