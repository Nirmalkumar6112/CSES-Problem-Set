#include<bits/stdc++.h>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> time(n);

    long sum = 0;

    for(int i=0;i<n;i++){
        cin>>time[i];
        sum += time[i];
    }

    sort(time.begin(),time.end());

    cout<<max(sum,(long)time[n-1] * 2)<<endl;
        
    return 0; 
}
