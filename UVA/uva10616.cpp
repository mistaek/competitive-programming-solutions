/*
UVa 10616
[NAME]
AC 
*/

//no clue why it started working lul

#include <cstdio>
#include <cstring>

typedef long long ll; 

ll A[205], memo[210][11][22]; // number, picked, sum  (state)
int n, q, d, m;

ll pick(int p, int w, int s){
    if(w == m){ //check
        if(s == 0) return 1; 
        return 0; 
    }
    if(p >= n) return 0; // if we are past boundary, return 0
    
    ll &address = memo[p][w][s];

    if(address != -1) return address; // if previously calculated, return it

    ll xx = 0, yy = 0; 

    ll temp = s+ A[p]; //temporary for negative mod calculations
    temp %= d; 
    if(temp < 0) temp+=d; 

    xx = pick(p+1, w+1, temp); // get all possible from pick
    yy = pick(p+1, w, (s) %d); // or not picking

    return address = xx+yy; // return 
}
int main(){
    int set = 0; 
    while(scanf("%d %d", &n, &q) == 2 && (n && q)){
        set++;
        printf("SET %d:\n", set);
        for(int i = 0; i < n; i++) scanf("%lld", &A[i]);
        for(int i = 0; i < q; i++){
            scanf("%d %d", &d, &m);
            memset(memo, -1, sizeof(memo));
            printf("QUERY %d: %lld\n", i+1, pick(0,0,0)); 
        }
    }
    return 0; 
}