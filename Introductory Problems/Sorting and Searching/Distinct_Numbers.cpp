#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,res = 0;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    sort(arr,arr+n);

    for(int i=1;i<n;i++){
        if(arr[i] != arr[i-1])
            res++;
    }
    cout<<res + 1<<endl;
    return 0;
}
