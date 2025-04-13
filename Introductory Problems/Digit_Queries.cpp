#include<bits/stdc++.h>
using namespace std; 

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin>>q;

    vector<ll> powerOfTen(19,1);
    for(int i=1;i<19;i++){
        powerOfTen[i] = powerOfTen[i-1] * 10;
    }

    while(q--){
        ll k;
        cin>>k;

        ll numberofDigitsCur = 0;
        ll numberofDigitsPrev = 0;
        int numberOfDigits = 0;

        for(int i=1;i<19;i++){
            numberofDigitsCur += (powerOfTen[i] - powerOfTen[i-1]) * i;

            if(numberofDigitsCur >= k){
                numberOfDigits = i;
                break;
            }

            numberofDigitsPrev += (powerOfTen[i] - powerOfTen[i-1]) * i;
        }

        ll low = powerOfTen[numberOfDigits - 1];
        ll high = powerOfTen[numberOfDigits] - 1;
        ll val = 0;
        ll startPosOfDigit;

        while(low <= high){
            ll mid = (low + high) / 2;
            ll midValStartPos = numberofDigitsPrev + 1 + (mid - powerOfTen[numberOfDigits - 1]) * numberOfDigits;

            if(midValStartPos <= k){
                if(mid > val){
                    val = mid;
                    startPosOfDigit = midValStartPos;
                }

                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        string number = to_string(val);

        cout<<number[k - startPosOfDigit]<<endl;
    }
    
    return 0; 
}
