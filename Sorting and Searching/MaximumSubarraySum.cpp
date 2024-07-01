#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
 
int main(){
    long long n;
    cin>>n;
    
    vector<long long> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    long long res = LONG_MIN;
    long long sum = 0;
 
    for(int i=0;i<n;i++){
        sum += arr[i];
        res = max(res,sum);
        if(sum < 0)
            sum = 0;
    }
    
    cout<<res<<endl;
    
    return 0;
}