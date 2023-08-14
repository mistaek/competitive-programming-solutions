/*
1798C
AC
*/

#include <iostream>

using namespace std; 

long long gcd(long long a, long long b){
    if(a==0) return b;
    return gcd(b %a, a);
}
long long lcm(long long a, long long b){
    return (a/gcd(a,b))*b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        long long ans = 1, curg, curl; 
        cin >> curg >> curl;
        curg *= curl; 

        for(int i = 1; i < n; i++){
            long long a, b; cin >> a >> b; 
            
            curg = gcd(curg, a * b);
            curl = lcm(curl, b);
            //cout << curg << " " << curl << "\n";
            if(curg % curl){
                //cout << "new tag needed\n";
                ans++; 
                curg = a * b; 
                curl = b; 
            } 
        }
        cout << ans << "\n";
    }
    return 0;
}