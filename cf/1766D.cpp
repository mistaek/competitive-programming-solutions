/*
1766D
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int dvd[10000001] = {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    

    for(long long i = 2; i<= 10000000; i++){
        if(dvd[i] == 0){
            dvd[i] = i;
            for(long long j = i*i; j <= 10000000; j+= i){
                dvd[j] = i; 
            }
        }
    }

    int n; cin >> n; 
    while(n--){
        long long x, y; cin >> x >> y;
        long long ans = 1e9;
        if(y-x == 1){
            cout << "-1\n"; continue;
        }
        long long diff = y-x;
        while(diff > 1){
            long long i = dvd[diff];
            long long g = x/i;
            g *= i; 
            if(g < x) g += i; 
            ans = min(ans, g-x);
            while(dvd[diff] == i) diff/=i;
        }
        cout << ans << "\n";
    }
    return 0;
}