#include<iostream>
using namespace std;

int main(){
    long int n,res = 0;
    cin>>n;

    while(n>0){
        n /= 5;
        res += n;
    }
    cout<<res;
    return 0;
}
