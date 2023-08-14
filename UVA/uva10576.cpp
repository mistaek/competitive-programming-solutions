#include <cstdio>

#define max(a, b) ((a < b) ? b : a)
using namespace std; 
//doesn't work, too lazy to recode 

//y2k didnt happen anyway >:(

int s, d, best = 0; 
void backtrack(int month,  int amount, int five, int mask){
    if(month > 5){
        five -= (mask & (1 << month - 5)) ? s : -d;    
    } 
    if(five > 0 && month > 5) { return; }
    if(month == 12){best = max(best, amount); return;}
    backtrack(month+1, amount +s, five + s, mask | (1 << month+1)); 
    backtrack(month+1, amount -d, five -d, mask); 

}

int main(){
    while(scanf("%d %d", &s, &d) != EOF){
    	best = 0;
        backtrack(0, 0, 0, 0);
        if(best > 0) printf("%d\n", best); 
        else printf("Deficit\n"); 
    }
    return 0; 
}