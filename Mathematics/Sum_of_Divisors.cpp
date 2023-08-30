#include<iostream>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

int solve(ll x){
    //return x * (x+1) / 2;
    return ((x % mod) * ((x+1) % mod) / 2) % mod;
}

int main(){
    ll n,sum=0;
    cin>>n;

    for(ll i = 1;i <= n;i++){
        ll r = n/(n/i);
        sum += (n/i) % mod * (solve(r) - solve(i-1) + mod) % mod;
        sum = (sum + mod) % mod;
        i = r;
    }
    cout<<sum<<endl;
    return 0;
}
