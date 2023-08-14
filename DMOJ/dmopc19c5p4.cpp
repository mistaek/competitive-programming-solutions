/*
dmopc p4
ray
work in progressioen
*/

//too lazy to do
#include <cstdio>
int money[100000], victim[100000], value[100000];

int extort(int n){
    
    while(victim[n] != -1){

    }
}
int main(){
    int ppl; int q; 
    scanf("%d %d", &ppl, &q); 
      
    for(int i = 0; i < ppl; i++){
        scanf("%d", &money[i]);
    }
    for(int i = 0; i < ppl; i++){
        int v; scanf("%d", &v); 
        victim[i] = v-1; 
    }
    for(int i = 0; i < ppl; i++){
        value[i] = extort(i); 
    }
    return 0;
}