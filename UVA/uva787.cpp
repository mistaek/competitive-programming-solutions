/*
UVa 787 Maximum Sub-sequence Product
[NAME]
WIP
*/

//not doable in c++?

#include <cstdio>

#define max(a, b) ((a<b) ? b : a)
int main(){
    int l; 
    while(scanf("%d", &l)!= EOF){
        int seq[100] = {l}, idx =1; 
        while(scanf("%d", &l), l!= -999999){ seq[idx] = l; idx++;} 
        long long max = -999999; long long p = 1; 
        for(int i = 0; i < idx; i++){
            p = 1; 
            for( int j = i; j < idx; j++) p*= seq[i]; 
            max = max(p, max); 
        }

        printf("%d\n", max);
    }

}