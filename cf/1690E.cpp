/*
1690E
almost too slow... AC
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        long long n, k; cin >> n >> k; 
        vector<long long> a(n), m(k, 0); 
        long long sum = 0; 
        for(int i = 0; i < n; i++){ cin >> a[i]; sum += a[i]; m[a[i] % k]++;}

        for(int j = 0; j< k; j++){
            for(int i = 0; i < k; i++){
                if(n == 0) break;
                if(m[j] == 0) break;
                long long diff = k - j + i ;
                diff %= k; 
                if(diff == j){
                    long long p = m[j]/2; 
                    sum -= p*i; 
                    m[j] -= 2*p;
                    n -= 2*p;
                }
                else{
                    long long p = min(m[j], m[diff]); 
                    sum -= p * i; 
                    m[j] -= p; 
                    m[diff] -= p;
                    n-= 2*p;
                }
            }
        }
        
        cout << sum/k << "\n";


    }
    return 0;
}