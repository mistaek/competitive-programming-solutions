/*
1634B
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
        int n; long long x, y; 
        cin >> n >> x >> y;

        long long s = 0; 
        for(int i = 0; i < n; i++){
            long long a; cin >> a; 
            s += a; 
            s %= 2; 
        }
        if((s + x) % 2 == y % 2) cout << "Alice\n"; 
        else cout << "Bob\n"; 
    }
    return 0;
}