/*
2108D
ac
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main(){
    int t; cin >> t; 
    int queriesUsed = 0;

    auto query = [&](int idx){
        ++queriesUsed;
        if(queriesUsed > 250){
            cout << "OVER CAP" << endl; // shouldn't occur
            return 0;
        }
        cout << "? " << idx << endl; 
        int qans; 
        cin >> qans; 
        return qans; 
    };
    while(t--){
        int n, k; cin >> n >> k; 
        vector<int> a(k), b(k);
        queriesUsed = 0;
        if(n == 2*k){
            cout << "! " << k << " " << k << endl; 
            continue;
        }
        
        int shift = 0, mismatch = 0;
        //determine a and b 
        for(int i = 1; i <= k; ++i) a[i-1] = query(i);
        for(int i = 1; i <= k; ++i) b[i-1] = query(n-k+i);
        while(a[0] != b[shift]) ++shift; 
        while(mismatch < k && a[mismatch] == b[(shift + mismatch)%k]) ++mismatch; 
        mismatch %= k; 
        // look for first 1 + xk which is not equal to a[0].
        int hi = (n-1)/k+1, lo = 1; 
        while(lo < hi){
            int mid = (hi+lo)/2; 
            int cmid = query(1 + mid*k); 
            if(cmid != a[0]){
                hi = mid; 
            }
            else lo = mid+1; 
        }
        
        //we didn't find any break
        if(lo == (n-1)/k + 1){
            if(mismatch == 0){ cout << "! -1" << endl; continue; } // the two permutations are cyclic shifts
            else{
                hi = (n-mismatch - 1)/k + 1, lo = 1; 
                while(lo < hi){
                    int mid = (hi+lo)/2; 
                    if(query(1 + mismatch + mid*k) != a[mismatch]) hi = mid;  
                    else lo = mid + 1; 
                }
            }
        }
        else{
            mismatch = 0; 
        }

        int left = 2 + mismatch + (lo - 1) * k, right = 1 + mismatch + lo * k, ind = 1;
        //we now know that the break in pattern occurs between [left, right]
        //cout << left << " " << right << "\n";
        right = min(right, n -k+1); 
        for(; left <= right; ++left){
            int ql = query(left); // number at current position
            
            if(ql != a[(mismatch + ind)%k] || left == right){
                // break found
                int prev = 0; 
                for(int i = 0; i < k; ++i){
                    if(b[i] == ql){
                        prev = b[(i + k - 1) %k]; 
                        break; 
                    }
                }
                // ambiguous if: previous number equals previous in b, and left-1 >= k 
                if(left - 2 >= k && prev == a[(mismatch + ind + k - 1) % k]){
                    cout << "! " << -1 << endl; 
                }
                else cout << "! " << left-1 << " " << n -left + 1 << endl; 
                break; 
            }

            ++ind; 
        }

    }
    return 0;
}