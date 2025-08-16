/*
1166D
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int q; cin >> q; 
    auto out = [](vector<long long>& a){
        cout <<a.size();  
        for(auto n : a){
            cout << " " << n; 
        }
        cout << "\n"; 
    };
    while(q--){
        long long a, b, m; cin >> a >> b >> m;
        long long curK = 0, cur = a, prev = a;
        vector<long long> seq{a};  
        while(cur+1 <= b){
            seq.push_back(cur + 1);
            prev = cur+1;
            cur += 1 + cur;
            curK++; 
        } 
        long long diff = b - prev;
        if(diff == 0){
            out(seq); 
            continue; 
        }
        if(curK == 0 || m == 1){
            // next num is too big or no more options
            cout << "-1\n"; 
            continue; 
        }
        for(int i = 1; i < curK; ++i){
            long long lo = 0, hi = m-1; 
            while(lo < hi){
                if(diff == 0) break; 
                long long mid = (lo+hi+1)/2; 
                // if we add mid here, then we add mid + mid + 2*mid + ... in total 
                // = (1 << (curK - i)) * mid
                // can overflow.. 
                bool condd = true; 
                if(numeric_limits<long long>::max()/mid  <= (1LL << (curK - i-1))) condd = false; 
                else if(mid * (1LL << (curK - i-1)) > diff) condd = false; 
                
                if(condd){
                    lo = mid; 
                }
                else{
                    hi = mid-1; 
                }
            } 
            diff -= (1LL << (curK - i-1)) * lo; 
            seq[i] += lo;
            for(int j = i+1; j <= curK; ++j){                
                seq[j] += (1LL << (j - i - 1)) * lo;
           } 
        } 

        if(diff <= m-1){
            seq[curK] += diff; 
            out(seq); 
        }
        else{
            cout << "-1\n"; 
        }        

    }
    return 0; 
}