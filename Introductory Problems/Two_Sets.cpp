#include<bits/stdc++.h>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    int sum = (n * (n+1)) / 2;

    if(sum % 2 != 0){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";

        vector<int> a;
        vector<int> b;

        if(n % 2 == 0){
            for(int i=0;i<n/2;i++){
                if(i % 2 == 0){
                    a.push_back(i+1);
                    a.push_back(n-i);
                }
                else{
                    b.push_back(i+1);
                    b.push_back(n-i);
                }
            }
        }
        else{
            for(int i=0;i<(n-1)/2;i++){
                if(i % 2 == 0){
                    a.push_back(i+1);
                    a.push_back(n-i-1);
                }
                else{
                    b.push_back(i+1);
                    b.push_back(n-i-1);
                }
            }

            if(a.size() > b.size()){
                b.push_back(n);
            }
            else{
                a.push_back(n);
            }
        }

        cout<<a.size()<<endl;
        for(int i:a){
            cout<<i<<" ";
        }

        cout<<endl;

        cout<<b.size()<<endl;
        for(int i:b){
            cout<<i<<" ";
        }
    }

    
    return 0; 
}
