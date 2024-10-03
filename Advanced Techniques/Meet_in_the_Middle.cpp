#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> subset_sums(const vector<int>& arr,int l,int r){
    int len = r - l + 1;
    vector<ll> res;
    
    for(int i=0;i<(1<<len);i++){
        ll sum = 0;
        for(int j=0;j<len;j++){
            if(i & (1<<j)){
                sum += arr[l+j];
            }
        }
        res.push_back(sum);
    }

    return res;
}

int main(){
    int N,x;
    cin>>N>>x;

    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    vector<ll> left = subset_sums(arr,0, N / 2 - 1);
	vector<ll> right = subset_sums(arr,N / 2, N - 1);
    
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    ll res = 0;
    for(auto it : left){ 
        auto maxi = upper_bound(right.begin(),right.end(),x - it);
        auto mini = lower_bound(right.begin(),right.end(),x - it);
        res += maxi - mini;
    }
    
    cout<<res<<endl;
    return 0;
}