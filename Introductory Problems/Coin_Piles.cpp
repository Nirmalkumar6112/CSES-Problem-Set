#include<bits/stdc++.h>
using namespace std; 

void solve(){
    int a,b;
    cin>>a>>b;

    if((a + b) % 3 != 0 || (a > 2*b) || (b > 2*a)){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0; 
}
