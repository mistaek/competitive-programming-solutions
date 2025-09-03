/*
1169A
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int n; cin >> n;

    vector<int> a(2*n); 
    for(int i = 0; i < 2*n; ++i){
        cin >> a[i];
    }    

    // bsearch cuz i am too lazy to think of a cleaner solution
    int ans = 2*n; 
    bool pos = true; 
    vector<bool> present(n+1, false); 
    for(int i = 0; i < n; ++i){
        present[a[i]] = true; 
    }
    if(present[1]) pos = false; 
    for(int i = n; i < 2*n; ++i){
        if(a[i] == 1){
            int ctr = 0; 
            for(int j = 1; j <= n; ++j){
                if(i + j - 1 < 2*n){ 
                    if(a[i + j - 1] != j){
                        pos = false; break; 
                    }
                }
                else{
                    if(!present[j]){
                        pos = false; 
                        break; 
                    }
                    present[a[n + ctr]] = true; 
                    ctr++;
                }
            }
            if(pos) ans = i -n; 
            break; 
        }
    }
    if(pos) cout << ans << "\n"; 
    else{
        //ans is between n and 2n 
        int lo = n, hi = 2*n; 
        while(lo < hi){
            pos = true; 
            int mid = (lo+hi)/2; 
            present = vector<bool>(n+1, false); 
            for(int i = 0; i < mid; ++i){
                present[a[i]] = true; 
            }
            for(int i = 1; i <= n; ++i){
                if(!present[i]){
                    pos = false; break; 
                }
                if(mid + i -1 < 2*n) present[a[mid + i - 1]] = true; 
            }
            if(pos){
                hi = mid; 
            }
            else{
                lo = mid + 1; 
            }
        }
        cout << lo << "\n";
    }
    return 0;
}
