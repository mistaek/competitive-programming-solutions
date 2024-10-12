/*
985D
AC
*/
#include <iostream>
#include <vector>
#include <limits>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);

    long long n, h; cin >> n >> h;  
    long long lo = 1, hi = 1e18; 
    while(lo < hi){
        long long m = (hi + lo)/2; 
        if(m <= h){
            if(std::numeric_limits<long long>::max()/m <= m+1){
                hi = m; 
                continue; 
            }

            long long sum = (m*(m+1))/2; 
            if(sum >= n){
                hi = m; 
            }
            else lo = m+1; 
            continue;
        }

        long long p = (m + h)/2; 
        long long sum = ((m + h) % 2) ? p : 0;

        // can make any number from 0 to p(p+1)/2 + thing
        if(std::numeric_limits<long long>::max()/p <= p+1){
            hi = m;
            continue; 
        }
        sum += (p*(p+1))/2;

        long long nt = p-h; 
        if(nt > 0){
            if(numeric_limits<long long>::max()/(p-1 + h) <= nt){
                hi = m; continue;
            }

            if(numeric_limits<long long>::max() - ((nt *(p-1 + h))/2) <= sum){
                hi = m; continue; 
            }

            sum += ((nt *(p-1 + h))/2); 
        }
        if(sum >= n) hi =m; 
        else lo = m+1;

    }

    cout << lo << "\n";
    return 0;
}