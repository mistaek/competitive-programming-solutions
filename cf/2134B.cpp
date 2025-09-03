/*
2134B
*/

#include <iostream>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    long long primes[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    int tc; cin >> tc; 
    while(tc--){
        long long n, k; cin >> n >> k; 
        long long a[n]; 
        for(int i = 0; i < n; ++i) cin >> a[i]; 
        if(k == 2){
            for(int i = 0; i < n; ++i){
                if(a[i] % 3 == 1){
                    a[i] += k; 
                }
                else if(a[i] % 3 == 2){
                    a[i] += 2LL * k; 
                }
                if(i) cout << " "; 
                cout << a[i]; 
            }
        }
        else if(k % 2){
            for(int i = 0; i < n; ++i){
                if(a[i] % 2) a[i] += k; 
                if(i) cout << " "; 
                cout << a[i]; 
            }
        }
        else{
            long long pp; 
            for(int i = 1; i < 12; ++i){
                if(k % primes[i]){
                    pp = primes[i]; break; 
                } 
            }
            // pp should be <= 20 and < k
            for(int i = 0; i < n; ++i){
                while(a[i] % pp){ 
                    // should be <= 20
                    a[i] += k; 
                }
                if(i) cout << " "; 
                cout << a[i]; 
            }
        }
        cout << "\n"; 
    }
    return 0;
}