/*
1004A
*/

#include <iostream>

using namespace std; 

int main(){
    long long n, d; 
    cin >> n >> d; 
    long long a[n]; 

    long long ans = 2; 
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(i){
            if(a[i-1] + d <= a[i] - d){
                if(a[i-1] + 2*d == a[i]) ++ans; 
                else ans+=2; 
            }
        } 
    }
    cout << ans << "\n";


    return 0;
}