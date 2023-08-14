/*
1644C
AC with hint
*/

#include <iostream>
#include <vector>
#include<algorithm> 
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 

    int t; cin >> t; 
    while(t--){
        int n, x; 
        cin >> n >> x; 
        vector<int> a(n); 
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<long long> mx(n); 
        for(int i = 1; i <= n; i++){
            long long sum =0; 
            for(int j = 0; j < n; j++){
                if(j < i) sum += a[j]; 
                else{
                    sum += a[j] - a[j-i];
                    mx[i-1] = max(mx[i-1], sum);
                }
                if(j == i-1) mx[i-1] = sum; 
            }
        }

        for(int i = 0; i<= n; i++){
            long long ans = 0; 
            for(int j = 0; j < n; j++){
                ans = max(ans, mx[j] + (min(i, j+1) * x));
            }
            cout << (i ? " " : "") << ans; 
        }
        cout << "\n";
    }

    return 0;
}