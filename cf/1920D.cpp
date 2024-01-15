/*
1920D
??
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std; 

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t; 

    while(t--){
        map<long long, long long> ogs; 
        vector<long long> unravel;
        long long len = 0; //current array length; 
        long long n, q; cin >> n >> q; 
        for(int i = 0; i < n; i++){
            long long b, x; cin >> b >> x; 
   
            if(len > 2e18) continue; //can ignore
            if(b == 1){
                ogs[++len] = x; 
                //cout << len << " " << x << "\n";
            }
            else{
                unravel.push_back(len); // mod by this
                long long llm = 2e18+1; 
                //overflow check
                if(llm / (x+1LL) < len) len = 2e18+1; // FLOAT ERROR 
                else{
                    len *= (x+1);
                }
                cout << (long long) (2e18 + 1) << "\n"; 

            }
            //cout << len << "\n";
        }
        reverse(unravel.begin(), unravel.end());
        
        for(long long i = 0; i < q; i++){
            if(i) cout << " "; 
            long long k; cin >> k; 
            bool out = false; 
            for(long long j = 0; j < unravel.size(); j++){ // this loop should never run mroe than 60 times
                if(ogs.find(k) != ogs.end()){
                    cout << ogs[k];
                    out = true; 
                    break; 
                }
                else{
                    k %= unravel[j];
                    if(k == 0) k = unravel[j];
                }
            }
            if(!out) cout << ogs[k];
        }
        cout << "\n";
    }
    
    return 0;
}