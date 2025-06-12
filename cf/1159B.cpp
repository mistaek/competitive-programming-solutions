    /*
    1159B
    */
     
    #include <iostream>
    #include <algorithm>
    using namespace std; 
     
    int main(){
        ios_base::sync_with_stdio(false); 
        cin.tie(0); cout.tie(0); 
     
        int ans = 1e9; 
        int n; cin >> n; 
        for(int i = 0; i < n; ++i){
            int a; cin >> a; 
            int gap = max(i, n-i - 1); 
            ans = min(ans, (a/gap));
        }
        cout << ans << "\n";
        return 0;
    }