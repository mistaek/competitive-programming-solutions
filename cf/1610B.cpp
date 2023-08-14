/*
1610B
AC
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<int> a(n); 
        for(int i = 0; i < n; i++) cin >> a[i];

        int i = 0, j = n-1; 
        int r1 = -1, r2 = -1; 
        while(i < j){
            if(a[i] != a[j]){
                r1 = a[i]; r2 = a[j]; 
                break;
            }
            i++; 
            j--;
        }
        bool a1 = true, a2=true;   
        i = 0, j = n-1; 
        while(i < j){
            while(a[i] == r1) i++; 
            while(a[j] == r1) j--; 
            if(i < j && a[i] != a[j]) a1 = false; 
            i++; j--;
        }
        i = 0, j = n-1;
        while(i < j){
            while(a[i] == r2) i++; 
            while(a[j] == r2) j--; 
            if(i < j && a[i] != a[j]) a2 = false; 
            i++; j--; 
        }

        if(a1 || a2) cout << "yes\n"; 
        else cout << "no\n";
    }
    return 0; 
}