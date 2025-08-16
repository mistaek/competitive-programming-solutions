/*
2128E1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std; 
/*
bool test(){
    int n = rand()% 10 + 1; 
    int k = rand() % n + 1; 
    int a[n]; 
    for(int i = 0; i < n; ++i){
        a[i] = rand() % n + 1; 
    }

    // SOL
    int lo = 1, hi = n;
    int l = 1, r =n; 
    // is there a k-subarray with median >= mid? 
    while(lo < hi){
        int mid = (lo + hi+1)/2; 
        int numBigger = 0, len = 0;
        for(int i = 0; i < k; ++i){
            if(a[i] >= mid){
                ++numBigger; 
            }
            ++len; 
        }
        bool cond = false; 
        int cutBigger = 0, cutSmaller = 0;
        for(int j = k; j < n+1; ++j){
            if(numBigger >= len - numBigger){
                cond = true; 
                r = j; l = j+1 -len;
                break; 
            }
            if(j == n) break; 
            if(a[j] >= mid){
                numBigger++; 
            }
            if(a[j-k] < mid){
                cutSmaller++; 
            }
            else{
                cutBigger++;
            }
            len++; 
            if(cutSmaller >=cutBigger){
                len = k; 
                numBigger -= cutBigger; 
                cutSmaller = 0, cutBigger = 0;
            }
        }
        if(cond){
            lo = mid; 
        }
        else{
            hi = mid-1; 
        }
    } 
    //cout << lo << " " << l << " " << r << "\n"; 

    //BF
    int best = 1, l2 = 0, r2 = 0;
    for(int i = 1; i <= n; ++i){
        cout << " I " << i << "\n"; 
        for(int j = 0; j <n; ++j){
            int numBigger = 0; 
            for(int j2 = j; j2 < n; ++j2){
                if(a[j2] >= i) ++numBigger; 
                cout << j << " " << j2 << " " << numBigger << " " << j2 - j + 1 << "\n";
                if(j2 - j + 1 >= k && numBigger >= j2 - j + 1 - numBigger){
                    best = i, l2= j +1, r2 = j2 + 1; 
                    break; 
                }
            }
        }
    }
    if(best != lo){
        cout << n << " " << k <<  "\n"; 
        for(int i = 0; i < n; ++i) cout << a[i] << " "; 
        cout << "\n"; 
        cout << lo << " " << l << " " << r  << "\n"; 
        cout << best << " " << l2 << " " << r2 << "\n"; 
        return false; 
    }
    return true; 
} */
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    /*while(test()){

    }
    return 0; */
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n); 
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        int lo = 1, hi = n;
        int l = 1, r =n; 
        // is there a k-subarray with median >= mid? 
        while(lo < hi){
            int mid = (lo + hi+1)/2; 
            int numBigger = 0, len = 0;
            for(int i = 0; i < k; ++i){
                if(a[i] >= mid){
                    ++numBigger; 
                }
                ++len; 
            }
            bool cond = false; 
            int cutBigger = 0, cutSmaller = 0;
            for(int j = k; j < n+1; ++j){
                if(numBigger >= len - numBigger){
                    cond = true; 
                    r = j; l = j+1 -len;
                    break; 
                }
                if(j == n) break; 
                if(a[j] >= mid){
                    numBigger++; 
                }
                if(a[j-k] < mid){
                    cutSmaller++; 
                }
                else{
                    cutBigger++;
                }
                len++; 
                if(cutSmaller >=cutBigger){
                    len = k; 
                    numBigger -= cutBigger; 
                    cutSmaller = 0, cutBigger = 0;
                }
            }
            if(cond){
                lo = mid; 
            }
            else{
                hi = mid-1; 
            }
        } 
        cout << lo << " " << l << " " << r << "\n"; 
    }
    return 0;
}