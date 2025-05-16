/*
1598C
ac
*/

#include <cstdio>
#include <map>

using namespace std; 
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        long long n = 0; scanf("%lld", &n); 
        long long a[n] = {}, s = 0;
        map<long long, long long> m;
        
        for(int i = 0; i < n; i++){
            scanf("%lld", &a[i]);
            if(m.find(a[i]) == m.end()) m[a[i]]= 1;
            else m[a[i]]++;
            s += a[i];
        }
        if((2*s)%n){
            printf("0\n");
            continue; 
        }
        long long d = (2 * s) /n;
        long long ans = 0;
        
        for(int i = 0; i < n; i++){
            if(d-a[i] == a[i]){
                ans += m[a[i]] - 1; 
            }
            else{
            if(m.find(d - a[i]) != m.end()){
                    ans += m[d - a[i]]; 
                }
            }
        }
        ans /= 2; 
        for(int i = 0; i < n; i++){
            if(d-a[i] == a[i]){

            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}