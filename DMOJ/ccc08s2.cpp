/*
ccc08s2
ac
*/

//simple?

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std; 

int main(){
    long long r = 0, ans = 0; 
    while(scanf("%lld", &r), r){
        ans = 0;
        for(int i = -r; i <= r; i++){
            int y = sqrt((r * r) -(i * i)); 
            ans += 2*y + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}