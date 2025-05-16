/*
1622A
WIP
*/
#include <cstdio>
#include <algorithm>

using namespace std; 

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        long long l[3]; scanf("%lld %lld %lld", &l[0], &l[1], &l[2]);
        sort(l, l+3); 
        if(l[0] == l[1]){
            if(l[2] % 2 == 0) printf("YES\n"); 
            else printf("NO\n");
        }
        else if(l[1] == l[2]){
            if(l[0] %2) printf("NO\n");
            else printf("YES\n"); 
        }
        else if(l[0] + l[1] == l[2]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}