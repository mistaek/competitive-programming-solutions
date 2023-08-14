/*
1787C
AC
*/

#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; 
    while(t--){
        long long n, s; 
        cin >> n >> s; 
        long long a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        long long ans1 = 0, ans2 = 0;
        long long ln = a[0], lm = a[0];

        
        for(int i = 1; i < n-1; i++){
            long long cn = min(min(a[i], s), a[i] - min(a[i], s)), cm = max(min(a[i], s), a[i] - min(a[i], s));

            long long a1, a2, a3, a4; 
            a1 = ans1 + ln * cn; 
            a2 = ans1 + ln * cm; 
            a3 = ans2 + lm * cn; 
            a4 = ans2 + lm * cm;

            ln = cm; 
            lm = cn;
            ans1 = min(a1, a3);
            ans2 = min(a2, a4);

        }
        ans1 += a[n-1] * ln; 
        ans2 += a[n-1] * lm;

        cout << min(ans1, ans2) << "\n";
    }
    return 0;
}