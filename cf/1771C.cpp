/*
1771C
AC
*/

#include <iostream>
#include <set> 
#include <vector>
using namespace std; 

vector<int> primes; 
int vis[100000] = {1, 1};
int vis2[100000] = {};
set<int> occ; 



int main(){
    primes.push_back(2); 
    for(int i = 4; i< 100000; i+= 2) vis[i] = 1; 
    for(long long i = 3; i< 100000; i+=2){
        if(vis[i] == 0){
            primes.push_back(i);
            //cout << i << "\n";
            for(long long j = i*i; j < 100000LL; j+= i){
                vis[j] = 1; 
            }
        }
    } 
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    int t; cin >> t; 
    int tc = 0; 
    while(t--){
        tc++;
        occ.clear();
        int n; cin >> n;
        bool ans = false; 
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(occ.count(a)){
                ans = true; 
            }
            if(ans) continue; 
            for(auto j : primes){
                if(ans) break; 
                if(a / j < j) break; 
                if(a % j) continue; 
                if(vis2[j] == tc){
                    ans = true; 
                }
                vis2[j] = tc; 
                while(a % j == 0) a /= j;
            }
            if(a > 1){ 
                if(a < 100000){
                    if(vis2[a] == tc){
                        ans = true; 
                    }
                    vis2[a] = tc; 

                }
                else{
                    if(occ.count(a)) ans = true;
                    occ.insert(a);
                }
            }
        }

        cout << ((ans) ? "yes" : "no") << "\n";
    }
    
    return 0;
}