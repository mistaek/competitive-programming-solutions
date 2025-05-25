/*
2110C
*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<int> d(n), l(n), r(n); 
        for(int i = 0; i < n; ++i){
            cin >> d[i]; 
        }
        for(int i = 0; i< n; ++i){
            cin >> l[i] >> r[i]; 
        }

        for(int i = n-2; i >= 0; --i){
            //update range based on next obstacle
            int nextl = l[i+1]; 
            if(d[i+1] != 0) nextl -=1; 
            int nextr = r[i+1]; 
            if(d[i+1] == 1) nextr -= 1;  
            l[i] = max(l[i], nextl); //must be at least l[i+1]-1 to make it to the next obstacle
            r[i] = min(r[i], nextr); //can't go over the next obstacle 
        }
        int curh = 0;
        bool pos = true; 
        for(int i = 0; i < n;++i){

            if(d[i] == 1){
                ++curh; 
            }
            else if(d[i] == -1){
                //go up if we need to
                if(curh < l[i]){
                    ++curh; d[i] = 1; 
                }
                else d[i] = 0; 
            }
            //cout << l[i] << " " << r[i] << " " << i << " " << curh << "\n";
            if(curh < l[i] || curh > r[i] || l[i] > r[i]){
                pos = false; break; 
            }
        }

        //for(int i = 0; i < n; ++i){ cout << l[i] << " " << r[i] << "\n";  }
        if(pos){
            for(int i = 0; i < n; ++i){
                if(i) cout << " "; 
                cout << d[i]; 
            }
            cout << "\n"; 
        }
        else cout << "-1\n";
        
    }
    return 0;
}