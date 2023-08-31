/*
1861D
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std; 

int main(){
    cin.tie(0); 
    ios::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 

        int a[n], besti = 0, bestcost = 0, bestDelta = 0, saved = 0, cost = 0, ans = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i){
                if(a[i-1] > a[i]){
                    saved++; 
                }
                else cost++;

                if(saved - cost >= bestDelta){
                    bestDelta = saved - cost; 
                    bestcost = cost;
                    besti = i; 
                }
            }
        }
        //always do
        int j = 0; 
        if(bestDelta >= 1){
            ans = bestcost + 1; 
            j = besti; 
            a[j] = -a[j];
            //cout << "Flipped 1 to " << j << " current cost " << ans << "\n";

        }
        for(int i = n-2; i >= j; i--){
            if(a[i] >= a[i+1]) ans++;
        }
        
        cout << ans << "\n";
        
    }
    
    return 0;
}