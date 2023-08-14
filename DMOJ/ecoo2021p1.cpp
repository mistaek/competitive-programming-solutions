/*
ecoo2021p1
ac
*/

#include <cstdio>

int main(){
    int t, itv, larry; scanf("%d %d %d", &t, &itv, &larry);
    for(int i = 1; i <= 3; i++){
        if(t + (i *itv) >= larry ){ printf("%d\n", t + (i*itv)); break;}
        if(i == 3) printf("Who knows...\n");
    }
    
    return 0;
}