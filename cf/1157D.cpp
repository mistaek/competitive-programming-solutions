    /*
    1157D
    */
     
    #include <iostream>
    using namespace std; 
     
     
    int main(){
        long long n, k; cin >> n >> k;
        
        long long lo = 1, hi = 1e9;
        bool pos = true; 
        for(long long i = 0; i < k; ++i){
            
            while(lo < hi){
                long long mid = (lo+hi+1)/2; 
                // find the first num such that its arith sequence is less than n
                if((k-i)*(2*mid + k-i-1)/2LL <= n){
                    lo = mid; 
                }
                else hi = mid-1; 
            }
            if(i == 0){
                // prelim test
                if(k * (2*lo + k-1)/2LL > n){
                    cout << "NO\n"; break; 
                }
                if(k >= 30 || ((1LL << k) - 1) * lo >=n){
                    cout << "YES\n"; 
                }
                else{
                    cout << "NO\n"; 
                    break; 
                }
            }
            if(i) cout << " "; 
            cout << lo; 
            n-=lo;
            //upd for next iter
            hi = 2*lo; 
     
            lo = lo+1; 
        }
     
        return 0;
    }