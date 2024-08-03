/*
959E
AC
*/
#include <iostream>

using namespace std; 

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    long long n; cin >> n; 
    --n; 
    long long ans = 0;
    long long cur = 1;
    while(n)
    {  
        long long num = n/2 + (n%2);
        n/=2; 
        ans += cur * num;
        cur *= 2;
    }

    cout << ans << "\n";
    return 0;
}