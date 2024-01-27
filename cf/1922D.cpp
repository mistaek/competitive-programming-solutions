/*
1922D
AC
*/

#include <set> 
#include <iostream>
#include <vector>


using namespace std; 

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<long long> a(n), d(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> d[i];
        }
        set<int> alive, chk; 
        for(int i = 0; i < n; i++){
            alive.insert(i);
            chk.insert(i);
        }
        for(int i = 0; i < n; i++){
            set<int> del, nchk; //deleted, check on next iter
            for(auto j : chk){
                auto it = alive.find(j);
                if(it == alive.end()) continue; 
                long long hp = d[j];
                if(it != alive.begin()){
                    auto it2 = prev(it); 
                    hp -= a[*it2];
                }
                auto it2 = next(it); 
                if(it2 != alive.end()) hp -= a[*it2];
                if(hp < 0){
                    del.insert(j);
                    if(it!= alive.begin()){
                        nchk.insert(*prev(it));
                    }
                    if(next(it) != alive.end()) nchk.insert(*next(it));
                    
                }
            }
            if(i) cout << " "; 
            cout << del.size();
            for(auto j : del) alive.erase(j); 
            chk = nchk; 
        }
        cout << "\n";
    }
    return 0;
}