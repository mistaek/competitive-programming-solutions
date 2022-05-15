/*
ccc 00 s4 
ray
AC (bottom up works)
wip (top down)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std; 

#define min(a, b) ((a < b) ? a : b)
//coin change problem
int d, cnum, c[33] = {}; 
int memo[5285];

//do top down later?
//void solve(){}
int main(){
    scanf("%d", &d); 
    scanf("%d", &cnum); 
    for(int i = 0; i < cnum; i++) scanf("%d", &c[i]);
    //sort(c, c+cnum, greater<int>());
    memset(memo, -1, sizeof(memo));
    memo[0] = 0;
    //bottom up
    for(int i = 1; i <= d; i++){
        for(int j = 0; j < cnum; j++){
            for(int k = 1; k <= i/c[j]; k++){
                if(memo[i - (k*c[j])] != -1){
                    memo[i] = (memo[i] == -1) ? memo[i - (k*c[j])] + k : min(memo[i], memo[i - (k*c[j])] + k);
                }
            }
        }
    } 

    if(memo[d] == -1) printf("Roberta acknowledges defeat.");
    else printf("Roberta wins in %d strokes.", memo[d]);
    
    /*printf("\n");
    for(int i = 0; i < d; i++){
    	printf("%d ", i); 
    }
    printf("\n"); 
    for(int i = 0; i < d; i++){
    	printf("%d", memo[i]);
    }*/
    return 0;
}