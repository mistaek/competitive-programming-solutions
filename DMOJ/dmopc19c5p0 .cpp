/*
DMOPC february 2020 forever and ever baybeee
Ray, fan of richardzhang
AC
*/

//gameinger

#include <cstdio>

using namespace std; 

int main(){
    int n, c; 
    scanf("%d %d", &n, &c); 
    char name[51]; int s; 
    for(int i = 0; i < n; i++){
        scanf(" %s %d", &name[0], &s);
        if(s > c){
            printf("%s will advance\n", name); 
        } 
        else printf("%s will not advance\n", name); 
        
    }
    return 0;
}