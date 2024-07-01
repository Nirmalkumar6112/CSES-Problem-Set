#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main(){
    int n,x;
    cin>>n>>x;
    
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second = i + 1;
    }
    
    sort(arr.begin(),arr.end());
    
    int l = 0;
    int r = n-1;
    
    while(l<r){
        if(arr[l].first + arr[r].first == x){
            cout<<arr[l].second<<" "<<arr[r].second;
            return 0;
        }
        else if((arr[l].first + arr[r].first) < x)
            l++;
        else
            r--;
    }
    
    cout<<"IMPOSSIBLE"<<endl;
    
    return 0;
}
