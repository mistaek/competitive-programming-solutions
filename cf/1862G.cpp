/*
1862G
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 

        vector<long long> a(n+1, 0); 
        multiset<long long> ms, md; 
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            ms.insert(a[i]);
        }

        for(auto it = next(ms.begin()); it != ms.end(); it++){
            long long last = *prev(it); 
            md.insert(*it - last); 
        }
        int q; cin >> q; 
        md.insert(0);
        for(int i = 0; i < q; i++){
            long long j, x; cin >> j >> x; 
            if(n == 1){
                a[j] = x; 
                cout << x << " "; 
                continue;
            }
                
            if(a[j] == *ms.begin()){
                long long diff = *next(ms.begin()) - a[j]; 
                md.erase(md.find(diff)); 
            }
            else if(a[j] == *prev(ms.end())){
                long long diff = *prev(ms.end()) - *prev(prev(ms.end()));
                md.erase(md.find(diff));
            }
            else{
                auto it = ms.find(a[j]); 
                long long nxt = *next(it), prv = *prev(it); 
                md.erase(md.find(nxt - a[j]));
                md.erase(md.find(a[j] - prv));
                md.insert(nxt - prv);
            }

            ms.erase(ms.find(a[j]));
            a[j] = x; 
            auto it = ms.insert(a[j]);

            if(it == ms.begin()){
                md.insert(*next(it) - *it);
            }
            else if(it == prev(ms.end())){
                md.insert(*it - *prev(it)); 
            }
            else{
                long long nxt = *next(it), prv = *prev(it); 
                md.erase(md.find(nxt - prv)); 
                md.insert(nxt - a[j]); 
                md.insert(a[j] - prv);
            }
    
            cout << *prev(ms.end()) + *prev(md.end()) << " ";
        }
        cout << "\n";

    }
    return 0;
}
