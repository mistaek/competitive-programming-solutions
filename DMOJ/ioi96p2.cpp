/*
ioi96 p2
ac - solved on laptop
*/

#include <cstdio>
#include <algorithm>
int machines[2][30], n, mn[2], Ft[2], helpful[2][40001];
using namespace std; 

int computeT(int type){
    int t = 0, processed = 0; 
    while(processed < n){
        t++;
        processed = 0; 
        for(int i = 0; i < mn[type]; i++){
            processed += t/machines[type][i]; 
        }
    }
    return Ft[type] = t; 
}

int calculate(){
    int copy = n; 
    
    for(int t = 1; t <= 40000; t++){
        //if(copy <= 0) break; //this should never trigger 
        for(int i = 0; i < mn[0]; i++){
            if(copy <= 0) break; 
            if(t % machines[0][i] == 0){ 
                copy--; //machine will finish a task here
                helpful[0][t]++;
            }
        }
        helpful[0][t] += helpful[0][t-1]; //previous total tasks completed. 
    }
    
    copy = n; 
    for(int t = Ft[1]; t >=0; t--){
        if(copy <= 0) break; //can trigger
        for(int i = 0; i < mn[1]; i++){
            if(copy <= 0) break; 

            //smth wrong here
            if((Ft[1] - t) % machines[1][i] == 0){
                copy--; 
                helpful[1][t-machines[1][i]]++;
            }
        }
    }
    for(int t = 1; t <= 40000; t++) helpful[1][t] += helpful[1][t-1];

    int d = 0; 
    while(++d){
        int t =0; 
        for(t = 0; t <= Ft[1]; t++){
            if(helpful[0][d + t] < helpful[1][t]) break; //if total finished < total started
        }
        if(t == Ft[1] + 1) break; 
    }
    return d; 
}
int main(){
    scanf("%d", &n); 
    scanf("%d", &mn[0]); 
    for(int i = 0; i < mn[0]; i++)scanf("%d", &machines[0][i]); 
    scanf("%d", &mn[1]);
    for(int i = 0; i < mn[1] ;i++)scanf("%d", &machines[1][i]);
    sort(machines[0], machines[0]+mn[0]);
    sort(machines[1], machines[1] + mn[1]); 
    computeT(0); computeT(1); 
    printf("%d\n", Ft[0]);
    int delay = calculate(); 
    //printf("%d %d\n", delay, Ft[1]); 
    //for(int i =0; i < 10; i++){printf("%d %d\n", helpful[0][i], helpful[1][i]);}
    printf("%d\n", delay + Ft[1]);
    //delay is where finisheda[t+d] >= startedb[t] for all t
    
    return 0;
}