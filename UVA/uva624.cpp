#include <cstdio>

#define max(a, b) ((b < a) ? a : b)

int durations[100000] = {}, best = 0; 
int n, numt; 
int ansm = 0; 
void backtrack(int d, int idx, int mask ){
	if(d > best){
        best = d; 
        ansm = mask; 
    }
	if(idx >= numt) return; 
    if(durations[idx] + d <= n) backtrack(d + durations[idx], idx +1, mask | (1 << idx)); 
    
    backtrack(d, idx+1, mask); 
    

}
int main(){
    while(scanf("%d", &n) != EOF){
        scanf("%d", &numt);
        ansm = 0; best = 0;
        for(int i = 0; i < numt; i++ ) scanf("%d", &durations[i]);
        backtrack(0, 0, ansm); 
        for(int i = 0; i < numt; i++){
        	if(ansm & (1 << i)) printf("%d ", durations[i]); 
        }
        printf("sum:%d\n", best);
    }
    return 0; 
}