/*
1829G
AC
*/

#include <iostream>
#include <algorithm>

using namespace std; 


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; 
    while(t--){
        long long n; cin >> n; 
        long long cnt = 1, row = 0, pos = 0;
        for(int i = 1; i <= 2023; i++){
            if(((i * (i+1))/2) >= n){
                row = i-1; // n is on the ith row
                pos = n - (((i-1)*(i))/2); // position in row
                break;
            }
        }
        //cout << row << " " << pos << "\n";
        long long ans = 0;
        while(row >= 0){
            long long hi = min(((row *(row+1))/2) + pos , (((row+1)*(row+2))/2));
            long long lo = max(((row *(row+1))/2) + pos - cnt, ((row *(row+1))/2));
            //cout << hi << " " << lo << "\n";
            //cout << ((hi * (hi+1) * (2*hi + 1))/6) << " " << ((lo * (lo+1) * (2*lo + 1))/6) << "\n";
            ans += ((hi * (hi+1) * (2*hi + 1))/6) - ((lo * (lo+1) * (2*lo + 1))/6);
            row--;
            cnt++;
        }
        cout << ans << "\n";

    }
    return 0;
}