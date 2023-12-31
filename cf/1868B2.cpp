/*
1868B2
*/

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std; 

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int t; 
    cin >> t; 
    while(t--){
        int n; cin >> n; 
        long long a[n], k = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            k += a[i];
        }
        k/=n;
        vector<pair<int, bool>> choice; 
        long long srcv[64] = {};
        bool pos = true; 
        for(int i = 0; i <n; i++){
            long long diff = abs(a[i] - k); 
            if(diff == 0) continue; 
            int lo = -1, hi = -1; 
            for(int j = 0; j < 32; j++){
                if(diff & (1 << j) && lo == -1){
                    lo = j; 
                }
                if((1 << j) > diff){ hi = j;break;}
            }
            if((1 << hi) - (1 << lo) != diff){
                pos = false; 
                break; 
            }
            if(lo == hi -1){
                choice.push_back({hi, (a[i] > k)});
            }
            else{
                if(a[i] > k){
                    srcv[lo]--; srcv[hi]++;
                }
                else{
                    srcv[lo]++; srcv[hi]--;
                }
            }
        }
        if(!pos){
            cout << "NO\n"; 
            continue; 
        }

        sort(choice.rbegin(), choice.rend());

        for(auto c : choice){
            if(c.second){
                if(srcv[c.first] < 0){
                    srcv[c.first]++; 
                    srcv[c.first - 1]--; 
                }
                else srcv[c.first-1]++;
            }
            else{
                if(srcv[c.first] > 0){
                    srcv[c.first]--; 
                    srcv[c.first-1]++; 
                }
                else srcv[c.first-1]--;
            }
        }
        for(int i = 0; i < 64; i++){
            if(srcv[i] != 0) pos = false;
        }
        cout << ((pos) ? "YES\n" : "NO\n"); 
    }
    return 0;
}