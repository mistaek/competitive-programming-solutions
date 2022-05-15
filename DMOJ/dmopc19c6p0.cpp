/*
dmopc19c60
ray 
wipwip
*/

//why is it dmopc 2019 contest 6 LOL

#include <cstdio>


int main(){
    int a, b, c; 
    scanf("%d %d %d", &a, &b, &c);

    if((a+b <= c) || (a + c <= b) || (c + b <= a)) printf("no"); 
    else printf("yes");
    return 0;
}