#include <cstdio>


//x + y + z = A
//xyz = B
//x^2 + y ^2 + z^2 = C

int main(){
    int TC; scanf("%d", &TC);
    while(TC--){
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C); 
        if(B < A || C < A){ printf("No solution.\n"); continue;}
        bool ans = false; 
        int x, y;
        for(x = -100; x < A-2; x++){
            if(ans) break; 
            for(y = x+1; y < A -1; y++){
                if(x == 0 || y == 0 ) continue;
                if(ans) break;
                int z1 = A - x - y; 
                int z2 = B/(x*y); 
                if(z1 != z2 || z1 == 0) continue; 
                int z = z1; if(z == x || z == y) continue; 
                if(z1 != z2)continue;                 
                if(x + y + z == A && x*y*z == B && (x*x) + (y*y) + (z*z) == C){ans = true; printf("%d %d %d\n", x, y, z); }
            }

        }
        if(!ans) printf("No solution.\n"); 
    }
    return 0;   
}