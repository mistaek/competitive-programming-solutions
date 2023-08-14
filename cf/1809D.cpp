/*
1809D
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t; 

    while(t--){
        string s; cin >> s; 

        
        long long ans = 0; 
        int b0 = 0, b1 = 0; 
        int psa0[s.length()] = {}, psa1[s.length()] = {}; 
        for(int idx = 0; idx < s.length(); idx++){
            psa1[idx] += s[idx] -'0'; 
            psa0[idx] -= s[idx] - '1';
            if(idx){
                psa1[idx]+= psa1[idx-1]; 
                psa0[idx] += psa0[idx-1];
            }
        }
        int i = 0, j = s.length() - 1; 
        while(true){
            if((psa1[j] - ((i == 0)? 0 : psa1[i-1]) == 0) || (psa0[j] - ((i == 0)? 0 : psa0[i-1]) == 0)){
                break; 
            }

            while(b0 == 0 && s[j] =='1'){
                j--;  // j is on the last 0
            }
            while(b1 == 0 && s[i] == '0'){
                i++; // i is on the first 1 
            }
            if(j-i + 1 <= 2){
                if(j >i) ans += 1e12; // 1 0 -> swap
                break; 
            }
            //otherwise we have identified some 1 block, unknown middle, some 0 block

            while(s[j] == '0'){
                b0++; 
                j--; 
            }
            // size of 0 block
            while(s[i] == '1'){
                b1++; 
                i++;
            }
            //size of 1 block

            long long del = min(b0, b1); //remove one or the other
            long long cost = 1e12 + 1; 
            if(b0 < b1){
                i -= b1; 
            }
            else if(b1 < b0){
                j += b0;
            }
            else{
                
            }
            b0 = 0; 
            b1 = 0;
            ans += del * cost; 
            cout << i << " " << j << "\n";
            if(j < i) break;
        }
        cout << ans << "\n";
    }
    return 0;
}