#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;

    vector<pair<int,int>> movies;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;

        movies.emplace_back(a,b);
    }

    sort(movies.begin(),movies.end(),[](auto &a,auto &b){
        return a.second < b.second;
    });

    int res = 0;
    int cur = 0;

    for(auto it : movies){
        if(it.first >= cur){
            cur = it.second;
            res++;
        }
    }

    cout<<res<<endl;

    return 0;
}
