/*
1646C
AC - think about parts of a problem you can fix first, allows for D&C
*/

#include <iostream>
#include <algorithm>


using namespace std;

long long a[12];

int countOnes(long long n){
    int ans = 0;
    while(n > 0){
        if(n & 1) ans++;
        n >>= 1;
    }
    return ans;
}
int compute(long long s, int idx){
    if(idx == 12 || a[idx] > s) return countOnes(s);

    return min(countOnes(s), min(1 + compute(s - a[idx], idx + 1), compute(s, idx+1)));
}



int main(){
    ios_base::sync_with_stdio(false);

    cin.tie(0);    
    a[0] = 6;
    for(long long i = 4; i <= 14; i++){
        a[i-3] = a[i-4] * i;
    }
    int t; cin >> t; 
    while(t--){
        long long n; cin >> n; 
        cout << compute(n, 0) << "\n";
    }
    return 0;
}