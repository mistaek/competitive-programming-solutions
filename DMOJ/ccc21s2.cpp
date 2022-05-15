/*
ccc 21 s2
ac
*/
#include <cstdio>

int m, n, k, ans = 0, rp = 0, cp = 0; 
int r[5000001], c[5000001];

void paint(char typ, int num){
    //printf("Start: %d gold\n", ans);
    if(typ == 'R'){
        if(r[num] == 0){
            ans += n - rp; //length of row
            cp+=2;
        }
        else{
            ans -= n-rp;
            cp-=2;
        
        }
        r[num] = 1-r[num];
    }
    else{
        if(c[num] == 0){
            ans += m -cp;
            rp+=2;
        }
        else{
            ans -= m -cp;
            rp-=2;
        }
        c[num] = 1-c[num];
    }
    //printf("End: %d gold\n", ans);
}
int main(){
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < k; i++){
        char t; int num; scanf(" %c %d", &t, &num);
        paint(t, num);
    }
    printf("%d\n", ans);
    return 0;
}