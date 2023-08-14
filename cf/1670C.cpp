/*
1670C
AC
*/

#include <iostream> 
#include <vector>

using namespace std; 

const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int t; cin>>t; 
    while(t--){
        int n; cin >> n; 
        vector<int> a(n), b(n);
        vector<vector<int>> dict(2, vector<int>(n));
        for(int i = 0; i < n; i++){
            cin >> a[i]; 
            dict[0][--a[i]] = i; 
        }

        for(int i = 0; i < n; i++){
            cin >> b[i];
            dict[1][--b[i]] = i; 
        }

        vector<vector<int>> s(2, vector<int>(n)); 
        for(int i = 0; i < n; i++){
            s[0][i] = i; 
            s[1][i] = n + i;
        }

        for(int i = 0; i < n; i++){
            if(a[i] == b[i]){ 
                s[1][i] = i;
            }
            else{
                if(s[1][i] == n+i && s[0][i] == i){
                    int wanted = b[i]; 
                    while(wanted != a[i]){
                        s[0][dict[0][wanted]]= i; 
                        wanted = b[dict[0][wanted]];
                    }
                    wanted = a[i]; 
                    while(wanted != b[i]){
                        s[1][dict[1][wanted]] = n+i; 
                        wanted = a[dict[1][wanted]];
                    }
                }
            }
        }
        long long ans = 1; 
        vector<int> picked(2*n, 0); 
        for(int i = 0; i < n; i++){
            int in; 
            cin >> in; 
            if(in == 0){
                continue;
            }
            else{
                in--; 
                if(a[i] == in) picked[s[0][i]] = 1; 
                else picked[s[1][i]] = 1; 
            }
        }
        for(int i = 0; i < n; i++){

            if(s[0][i] == i && s[1][i] == n+i && picked[i] == 0 && picked[n+i] == 0) ans *= 2; 
            ans %= mod; 
        }
        cout << ans << endl; 

        
    }
    return 0;
}