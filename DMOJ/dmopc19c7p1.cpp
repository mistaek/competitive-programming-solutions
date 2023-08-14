/*
dmopc2019 7 p1
ray
wip
*/
//why p0 so hard!
//why p1 so hard!
#include <cstdio>
#include <cstring> 
//scuffed program
int cc[5000] = {};
int main(){
    int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
    int n = 0; 
    int left[3] = {a, b, c};
    bool inv = false; 
    for(int i = 0; i < 5000; i++) cc[i] = 4; 
    while(left[0] + left[1] + left[2]){
        
        for(int i = 2; i >= 0; i--){
            if(left[i]){ 
                cc[n] -= i+1; 
                cc[n+1] -= i+1;
                left[i]--;
            }
            else if(i == 0) inv = true; 
        }
        if(inv) break; 
        n++;
    }
    n+=1; 
    //printf("%d carbons used\n", n);
    if(inv){
        printf("invalid");
    }
    else{
        int rem = d; 
        for(int i = 0; i < n; i++){
            //printf("%d ", cc[i]);
            rem -= cc[i]; 
        }
        //printf("\n");
        if(rem != 0) printf("invalid"); 
        else printf("C%dH%d", n, d);
    }
    return 0;
}