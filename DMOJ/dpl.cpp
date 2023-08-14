/*
deque (dpl)
ray
wip 
*/

//oompa loompa

#include <cstdio>
#include <cstring>
#define max(a, b) ((a > b) ? a : b)
typedef long long ll; 

ll m[3000][3000] = {};
int main(){
    int n; scanf("%d", &n); 
    ll dq[n];
    for(int i = 0; i < n; i++){
        scanf("%lld", &dq[i]);
    }
    // i did greedy before, it no werk :( 
    //time for dyanmic prgoraming i love dynamic program!!


    for(int l = n-1; l >= 0; l--){
        for(int r = l; r < n; r++){
            if(r == l) m[l][r] = dq[l];
            else m[l][r] = max(dq[r] - m[l][r-1] , dq[l] - m[l+1][r] );
        }
    }
    printf("%lld", m[0][n-1]);
    return 0;
}