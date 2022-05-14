/*
1610B
WIP
*/

#include <cstdio>

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n); 
        int a[n]; for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        int p1 = 0, p2 = n-1, amnt[n + 1][2] = {}, ineq = 0, ineqn = a[0];
        while(p1 < p2){
            amnt[a[p1]][0]++; 
            amnt[a[p2]][1]++;
            p1++;
            p2--;
        }
        for(int i = 1; i <= n; i++){
            if(amnt[i][0] != amnt[i][1]){
                ineq++; 
                ineqn = i;
            }
        }
        if(ineq > 2) printf("NO\n"); 
        else{
            bool t = true;
            p1 = 0; p2 = n-1;  
            while(p1 < p2){
                if(a[p1] == ineqn) p1++; 
                else if(a[p2] == ineqn) p2--;
                else if(a[p1] != a[p2]){
                    t = false; 
                    break;
                }  
                else{
                    p1++; 
                    p2--;
                }
            }
            if(t) printf("YES\n"); 
            else printf("NO\n");
        }
    }
    return 0;
}