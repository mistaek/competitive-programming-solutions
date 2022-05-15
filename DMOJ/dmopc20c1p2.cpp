/*
dmopc20c1 p2
wip
*/

#include <cstdio>

int main(){
    int n, d; scanf("%d %d", &n, &d); 
    int a[n+1], psa[n+1] = {}; for(int i = 1; i <= n; i++) {scanf("%d", &a[i]); psa[i] = a[i] + psa[i-1];}

    int curs = 1, cure = n; 
    for(int i = 0; i < d; i++){
        int cut; scanf("%d", &cut);
        int fsum, ssum; 
        fsum = psa[curs+cut-1]-psa[curs-1];
        ssum = psa[cure] - psa[curs+cut-1];
        if(fsum < ssum){
            cure = curs+cut-1; 
            printf("%d\n",ssum);
        }
        else{
            curs = curs+cut; 
            printf("%d\n", fsum);
        }
    }
    return 0;
}