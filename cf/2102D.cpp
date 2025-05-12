/*
2102A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional> 
using namespace std; 

int main(){
    cin.tie(0); cout.tie(0); 
    ios_base::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        set<int> odds, evens; 
        vector<int> pos(n+1, 0); 
        vector<int> a(n); 
        for(int i = 0; i < n;++i){
            cin >> a[i]; 
            pos[a[i]] = i; 
            if(i % 2) odds.insert(a[i]); 
            else evens.insert(a[i]); 
        }

        function<void(int,int)> aswap = [&](int idx, int idx2){
            if(idx == n-1 || idx2 == n-1) return; 
            pos[a[idx]] = idx2; 
            pos[a[idx+1]] = idx2+1; 
            pos[a[idx2]] = idx; 
            pos[a[idx2+1]] = idx+1; 
            swap(a[idx], a[idx2]); 
            swap(a[idx + 1], a[idx2+1]); 
        }; 

        for(int i = 0; i < n-3; ++i){
            if(i % 2){
                // move best odd into position

                int best = *odds.begin(); 
                odds.erase(odds.begin()); 
                if(pos[best] == n-1){
                    if(i < n-4){
                        aswap(n-2, n-4); 
                    }
                    else{
                        break; //cant improve
                    }
                }
                aswap(i, pos[best]); 
            }
            else{
                int best = *evens.begin(); 
                evens.erase(evens.begin()); 
                if(pos[best] == n-1){
                    if(i < n-4){
                        aswap(n-2, n-4); 
                    }
                    else{
                        break; //cant improve
                    }
                }
                
                aswap(i, pos[best]); 
            }
        }
        for(int i = 0; i < n; ++i){
            if(i) cout << " "; 
            cout << a[i]; 
        }
        cout << "\n";
    }
    return 0;
}