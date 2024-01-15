/*
1896D
AC
*/

#include <iostream>
#include <set>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n, q; cin >> n >> q; 
        int a[n+1];
        set<int> ones; 
        int m[2] = {}, sum = 0; 
        for(int i = 1; i <= n; i++){
            cin >> a[i]; sum += a[i];
            if(a[i] == 1) ones.insert(i);
        }

        m[sum % 2] = sum; 
        if(ones.empty()) m[1] =0;
        else{
            m[1 - (sum % 2)] = sum - 1 - (2 * min(*ones.begin() - 1, n - *ones.rbegin()));
        }
        for(int i = 0; i < q; i++){
            int type; cin >> type; 
            if(type == 1){
                int v; cin >> v; 
                cout << ((v > m[v % 2]) ? "NO\n" : "YES\n");
            } 
            else{
                int idx; cin >> idx;
                sum -= a[idx];
                ones.erase(idx); 
                cin >> a[idx];
                sum += a[idx]; 
                if(a[idx] == 1) ones.insert(idx);

                m[sum % 2] = sum; 

                if(ones.empty()) m[1] =0;
                else{
                    int smallest = min(*ones.begin() - 1, n - *ones.rbegin());
                    m[1 - (sum % 2)] = sum - 1 - 2 * smallest;
                }
            }
        }



    }
    return 0;
}