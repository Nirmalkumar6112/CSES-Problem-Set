#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s;
    int res = 0,c=0;
    char temp;
    cin>>s;

    for(int i=0;i<s.length();i++){
        if(s[i] != temp){
            temp = s[i];
            c = 0;
        }
        if(s[i] == temp)
            c++;
        res = max(res,c);
    }
    cout<<res;
    return 0;
}
