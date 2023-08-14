/*
UVa 11100 - The Trip, 2007
[NAME]
WIP
*/

#include <cstdio>
#include <set>
#include <algorithm>

using namespace std; 

int p[10001], s[10001];
bool printed[10001], filled[100001], first = true; 

//ds without path compression

void countSets(int bags){
    int ans = 0; 
    for(int i = 0; i < bags; i++){
        if(p[i] == i) ans++;
    }
    printf("%d\n", ans); 
}

int main(){
    int bags; 
    while(scanf("%d", &bags), bags){
    	if(first) first = false; 
    	else printf("\n"); 
        for(int i = 0; i < bags; i++){
            scanf("%d", &s[i]); 
            p[i] = i; 
            printed[i] = false; 
            filled[i] = false;
        }
        sort(s, s+bags);
        for(int i = 0; i < bags; i++){
            if(p[i] == i){
                for(int j = i+1; j < bags; j++){
                    if(s[i] < s[j] && !filled[j]){ p[i] = p[j];  filled[j] = true; break;}
                   
                }
            }
        }  
        countSets(bags);
        for(int i = 0; i < bags; i++){
            if(!printed[i]){
                int x = i; 
                while(p[x] != x){
                    printf("%d ",s[x]); 
                    printed[x] = true; 
                    x = p[x];
                }
                printf("%d\n", s[x]);
                printed[x] = true; 
            }
        } 
        
    } 

    return 0; 
}