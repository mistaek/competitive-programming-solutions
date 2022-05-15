/*
* UVa 11413
* [Name]
* WIP
*/

#include <cstdio>

int bottles[1000000], vessels, containers;
bool tryCap(int n){
	int sz = 0;  int used = 0;
    for(int i = 0; i < vessels; i++){
        if(bottles[i] > n) return false; 
        if(sz + bottles[i] > n) sz = 0; 
        if(sz == 0) used++;
        sz +=bottles[i];
        if(used > containers) return false; 

    }
    return true;
}
int main(){
    while(scanf("%d %d", &vessels, &containers) != EOF){
        int max = 0; 
        for(int i =0; i < vessels; i++){scanf("%d", &bottles[i]); max+= bottles[i];}
         
        int min = 1; 
        int best = max+1; 
        int mid = (min+max)/2; 
        
        while(min <= max){
        	mid = min + (-min+max)/2; 
            if(tryCap(mid)){
                best = mid; 
                max = mid -1; 
            }
            else min = mid+1; 
        }
        printf("%d\n", best); 
    }
    return 0; 
}