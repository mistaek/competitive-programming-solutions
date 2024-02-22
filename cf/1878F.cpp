/*
1878F
AC
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std; 

map<long long, long long> factors; 
long long d = 1; 

void factor(int x){ // 10^3 ops, sqrt n
    for(int i = 2; i* i <= x; i++){
        long long cnt = 0; 
        while(x % i == 0){
            x /= i; 
            cnt++;
        }
        d /= (factors[i]+1); 
        factors[i] += cnt; 
        d *= (factors[i] + 1);
    }
    if(x > 1){
        d/= factors[x] + 1; 
        factors[x] += 1; 
        d *= factors[x] + 1LL; 
    }
}
int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0); 
    int t; cin >> t; 
    while(t--){
        long long n, q; cin >> n >> q; 
        factors.clear();
        d = 1;
        factor(n);
        for(int i = 0; i < q; i++){
            int type, x; cin >> type;  
            if(type == 1){
                cin >> x; 
                factor(x);
                bool pos = true; 
                long long dc = d; 
                for(long long j = 2; j * j <= d; j++){
                    long long cnt = 0; 
                    while(dc % j == 0){
                        dc /= j; 
                        cnt++; 
                    }
                    pos = pos && (cnt <= factors[j]); 
                }
                if(dc > 1) pos = pos && (1 <= factors[dc]);

                cout << (pos ? "YES" : "NO") << "\n";
            }
            else{
                factors.clear(); 
                d = 1;
                factor(n); 
            }

        } 
        //cout << "\n";

    }
    return 0;
}