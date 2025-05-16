/*
1609C
ac
*/

#include <cstdio>
int p[1000100];
int main(){
    p[0] = 1; p[1] = 1;
    //printf("ruh roh\n"); 
    for(int i = 4; i <= 1000000; i+= 2) p[i] = 1; 
    
    for(int i = 3; i <= 1000; i+= 2){
        if(p[i] == 0){
            for(int j = i*i; j <= 1000000; j += i) p[j] = 1; 
        }
    }
    /* 
    for(int i = 0; i < 100; i++){
        if(p[i] == 0) printf(" %d", i); 
    }
    
    printf("\n");
    return 0;
    */
    int t; scanf("%d", &t); 
    while(t--){
        long long n, e; scanf("%lld %lld", &n, &e);
        long long uo[n] = {}, up[n] = {}, fp[n] = {}, a[n]; 
        for(int i = 0; i < n; i++){
            scanf("%lld", &a[i]); 
            if(a[i] == 1) uo[i]++;
            if(p[a[i]] == 0) up[i]++;
        }
        long long ans = 0;
        for(int i = e; i < n; i++){
            if(a[i] == 1){
                fp[i] += up[i-e] + fp[i-e];
                uo[i]+= uo[i-e];
                ans += fp[i];
            }
            if(p[a[i]] == 0){
                fp[i] += uo[i-e];
                ans += fp[i];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}