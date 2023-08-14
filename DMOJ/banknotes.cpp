/*
dmoj banknoetes for dev
am i disabled?
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <functional>
using namespace std; 
pair<int, int> denom[200];
int memo[200][20001];int n;

int bc(int t, int remw, int used){
    //printf("%d %d %d\n", t, remw, used);
    if(remw == 0) return memo[t][remw] = 0;
    if(t >= n && remw >0) return 1e9;
    //if(used > denom[t].second ) return 1e9;
    if(used == denom[t].second || remw < denom[t].first){ int x =bc(t+1, remw, 0); memo[t][remw] = (memo[t][remw] == -1)? x : min(memo[t][remw], x); return x;}

    if(memo[t][remw] != -1) return memo[t][remw];
    else{
        //if(t == 2 && remw == 5 && used == 1) printf("???\n");

        return memo[t][remw] = min(bc(t+1, remw, 0), bc(t, remw-denom[t].first, used+1)+1);
    }
    
}
int main(){
    scanf("%d", &n); 
    for(int i = 0; i < n; i++){ scanf("%d", &denom[i].first); 
    //printf("%d ", denom[i].first); 
    }
    //printf("\n");
    for(int i = 0; i < n; i++){ scanf("%d", &denom[i].second); 
    //printf("%d ", denom[i].second); 
    }
    //printf("\n");
    int obj; scanf("%d", &obj);
    for(int i = 0; i < 200; i++){
        for(int j = 0; j <= 20000; j++) memo[i][j] = -1;
    }
    
    printf("%d\n",bc(0, obj, 0));
    /*
    for(int i = 0; i < 3; i++){
        for(int j= 0; j <=10; j++) printf("%d ", memo[i][j]); 
        printf("\n");
    }
    */
    return 0;
}