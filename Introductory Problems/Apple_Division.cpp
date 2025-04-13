#include<bits/stdc++.h>
using namespace std; 

#define ll long long 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> weights(n);
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }

    ll res = LLONG_MAX;

    for(int i=0;i<(1 << n);i++){
        ll a = 0, b = 0;

        for(int j=0;j<n;j++){
            if(i & (1 << j)){
                a += weights[j];
            }
            else{
                b += weights[j];
            }
        }

        res = min(res,abs(a - b));
    }

    cout<<res<<endl;
    
    return 0; 
}
