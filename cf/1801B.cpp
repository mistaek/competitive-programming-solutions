/*
1801B
ac, bad sol..
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;

        vector<pair<int, int>> a(n), b(n), us(n);  
        for(int i = 0; i < n; i++){
            cin >> a[i].first >> b[i].first; 
            us[i] = {a[i].first, b[i].first}; 
            a[i].second = b[i].second = i;
        }
        sort(a.begin(), a.end()); 
        
        sort(b.begin(), b.end());

        int ai = n-1, bi = n-1, ans = 1e9; 
        bool invalid = false, pos = true;
        while(b[bi].first > a[ai].first){
            bi--; 
            if(bi == -1){
                invalid = true; 
                break; 
            }
        }
        if(bi == -1 || a[ai].second == b[bi].second) pos = false; 
        while(true){
            if(bi == -1) break; 
            if(pos){
                ans = min(ans, abs(a[ai].first - b[bi].first));
            }
            if(us[a[ai].second].second > b[bi].first) invalid = true;
            if(invalid) break; 

            while(ai > 0 && a[ai-1].first >= b[bi].first){
                if(us[a[ai].second].second > b[bi].first) invalid = true;
                if(invalid) break; 
                ai--; 
                if(a[ai].second != b[bi].second) pos = true; 
                else pos = false; 
                if(pos){
                    ans = min(ans, abs(a[ai].first - b[bi].first));
                }
            }
            if(invalid || bi == 0) break; 
            else{
                if(us[b[bi].second].first > a[ai].first){
                    invalid = true; 
                }
                else if(us[b[bi].second].first == a[ai].first && a[ai].second != b[bi].second){
                    invalid = true; 
                }
                else bi--;
                if(b[bi].second == a[ai].second){
                    pos = false; 
                } 
                else pos = true; 
            }
        }
        //cout << "\n";
        ai = n-1; bi = n-1; invalid = false; pos = true; 
        while(a[ai].first > b[bi].first){
            ai--; 
            if(ai == -1){
                invalid = true; 
                break; 
            }
        }
        if(ai == -1 || a[ai].second == b[bi].second) pos = false; 
        while(true){
            if(ai == -1) break; 
            if(pos){
                ans = min(ans, abs(a[ai].first - b[bi].first));
            }
            if(us[b[bi].second].first > a[ai].first) invalid = true;
            if(invalid) break; 

            while(bi > 0 && b[bi-1].first >= a[ai].first){
                if(us[b[bi].second].first > a[ai].first) invalid = true;
                if(invalid) break; 
                bi--; 
                if(a[ai].second != b[bi].second) pos = true; 
                else pos = false; 
                if(pos){
                    ans = min(ans, abs(a[ai].first - b[bi].first));
                }
            }
            if(invalid || ai == 0) break; 
            else{
                if(us[a[ai].second].second > b[bi].first){
                    invalid = true; 
                }
                else if(us[a[ai].second].second == b[bi].first && a[ai].second != b[bi].second){
                    invalid = true; 
                }
                else ai--;
                if(b[bi].second == a[ai].second){
                    pos = false; 
                } 
                else pos = true; 
            }
        }
        cout << ans << "\n";

    }
    return 0;
}