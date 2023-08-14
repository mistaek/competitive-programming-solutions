/*
1840D
AC
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        vector<int> a(n); 
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(n == 1){
            cout << "0\n"; 
            continue; 
        }
        sort(a.begin(), a.end()); 
        int lo = 0, hi = 1e9;
        while(lo < hi){
            int mid = lo + hi;
            mid/=2; 
            bool possible = true; 
            int cnt = 1; 
            int cpt[3] = {};
            cpt[0] = a[0] + mid; 
            for(int i = 0; i < n; i++){
                if(a[i] - cpt[cnt-1] > mid){
                    if(cnt == 3){
                        possible = false; 
                        break; 
                    }
                    else{
                        cnt++; 
                        cpt[cnt-1] = a[i] + mid;
                    }
                }
            }
            if(possible){
                hi = mid; 
            }
            else{
                lo = mid+1; 
            }
        }
        cout << lo << "\n";
    }
    return 0;
}