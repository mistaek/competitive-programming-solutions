/*
1839A
*/

#include <iostream>
#include <stack>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int dig[n];
        for(int i = 0; i < n; i++){
            cin >> dig[i];
        }
        if(dig[n-1] == 1){
            cout << "NO\n";
            continue; 
        }
        stack<int> ops;
        int streak = 0;
        for(int i = 0; i < n; i++){
            if(dig[i] == 0){
                ops.push(streak);
                for(int i = 0; i < streak; i++) ops.push(0);
                streak = 0;
            }
            else streak++;
        }
        cout << "YES\n";
        for(int i = 0; i < n; i++){
            if(i) cout << " "; 
            cout << ops.top(); 
            ops.pop();
        }
        cout << "\n";
    }   
    return 0;
}