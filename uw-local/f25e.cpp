#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int n, m; 
    while(true){
        cin >> n >> m; 
        if(n == 0 && m == 0) break; 
        vector<long long> a(n), b(m); 
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < m; ++i) cin >> b[i]; 

        sort(a.begin(), a.end()); 
        sort(b.begin(), b.end()); 
        long long filled = 0, cap = 0; 
        int j = 0; 
        for(int i = 0; i < n; ++i){
            while(j < (int)b.size() && b[j] < a[i]) ++j;
            if(j == (int)b.size()) break; 
            cap += b[j]; 
            ++filled;
            ++j; 
        }
        if(filled == n) cout << cap << "\n"; 
        else cout << "Impossible\n"; 
    }
    return 0;
}