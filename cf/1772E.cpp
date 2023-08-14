/*
1772E
AC
*/

#include <iostream>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int a[n+1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        int cnt1 = 0, cnt2 = 0, overlap=0;
        for(int i = 1; i <= n; i++){
            if(a[i] != i) cnt1++;
            if(a[i] != n-i + 1) cnt2++;
            if(a[i]!= i && a[i] != n-i+1){
                overlap++; 
            }
        }
        
        if(cnt1 > cnt2){
            if(cnt1 - cnt2 <= overlap) cout << "Tie\n";
            else cout << "Second\n"; 
        }
        else{
            if(cnt2 - cnt1 < overlap) cout << "Tie\n";
            else cout << "First\n";
        }
        

    }
    return 0;
}