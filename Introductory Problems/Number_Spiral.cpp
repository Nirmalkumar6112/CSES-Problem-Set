#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long x,y;
    cin>>y>>x;

    long long maxi = max(x,y);
    long long sq = (maxi - 1) * (maxi - 1);

    if(maxi & 1){
        if(x > y){
            cout<<(maxi * maxi) - y + 1<<endl;
        }
        else{
            cout<<sq + x<<endl;
        }
    }
    else{
        if(x > y){
            cout<<sq + y<<endl;
        }
        else{
            cout<<(maxi * maxi) - x + 1<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long t;
    cin>>t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
