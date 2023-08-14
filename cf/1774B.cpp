/*
1744B
AC
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t; cin >> t; 
    while(t--){
        int n, m, k; cin >> n >> m >> k; 
        vector<int> a(m); 
        for(int i = 0; i < m; i++) cin >> a[i]; 
        sort(a.begin(), a.end(),greater<int>()); 
        int i = 0; 
        int j = 0; 
        bool ans = true; 
        while(i < m && j < k){
            int slots = n / k; 
            if(j < n % k) slots++; 
            if(a[i] > slots) ans = false; 
            i++;
            j++;
        }
        if(ans) cout << "yes\n"; 
        else cout << "no\n";
    }
    return 0; 
}