/*
UVa 10819
[NAME]
AC
*/

#include <cstdio>
#include <cstring>

int m, n, v[110], p[110]; 
int memo[110][15000]; 

#define max(a, b) ((a > b) ? a : b)
int pick(int id, int w){
	if(w > m + 200 || (w > m && m < 1800)) return -1000; 

    //IMPORTANT: MONEY CHECK
    if(id == n){
        if(w > m && w <= 2000)
            return -1000;
        return 0;
    }


    //tricky
    if(memo[id][w] != -1) return memo[id][w]; 
    return memo[id][w] = max(pick(id+1, w), v[id] + pick(id+1, w + p[id]));
     
}
int main(){
    while(scanf("%d %d", &m ,&n) != EOF){
        for(int i = 0; i < n; i++) scanf("%d %d", &p[i], &v[i]); 
        memset(memo, -1, sizeof(memo));
        printf("%d\n", pick(0, 0));
        
    }
    return 0; 
}