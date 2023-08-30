#include<iostream>
using namespace std;

#define mod 1000000007;

int main(){
    int n,ans=1;
    cin>>n;

    for(int i=0;i<n;i++){
        ans *= 2;
        ans %= mod;
    }
    cout<<ans;
    return 0;
}
