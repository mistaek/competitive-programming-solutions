/*
DMOPC 2019 contest 5 in febuary 2020
ray
wip
*/

#include <cstdio>
#include <iostream>

using namespace std;
//reichard epicc

int other(int a){
    if(a == 1) return 0; 
    else return 1;
}
int main(){
    int n, health; 
    scanf("%d %d", &n, &health); 
   
    pair<char, int> a[n], b[n]; 
    for(int i = 0; i < n; i++){
        scanf(" %c %d", &a[i].first, &a[i].second); 
    }
    for(int i = 0; i < n; i++){
        scanf(" %c %d", &b[i].first, &b[i].second); 
    }

    //simulate
    int hp[2] = {health, health}; int state = 0; 
    for(int i = 0; i < n; i++){
        //charlie's turn
        if(a[i].first == 'A'){
            if(i == 0) hp[1] -= a[i].second;  
            else if(b[i-1].first != 'D') hp[1] -= a[i].second; 
        }
        else if(a[i].first == 'D'){
            if(b[i].first !='A') hp[0] -= a[i].second; 
        }
        if(hp[0] <= 0){
            state = -1; 
            break;
        }
        if(hp[1] <=0){
            state = 1; 
            break;
        }
        //enemy turn
        if(b[i].first == 'A'){
            if(a[i].first != 'D') hp[0] -= b[i].second; 
        }
        else if(b[i].first == 'D'){
            if(i == n-1) hp[1] -= b[i].second; 
            else if(a[i+1].first == 'D') hp[1] -= b[i].second; 
        }
        if(hp[0] <= 0){
            state = -1; 
            break;
        }
        if(hp[1] <=0){
            state = 1; 
            break;
        }
        //printf("Charlie: %d Enemy: %d\n", hp[0], hp[1]);
    }

    //output
    if(state == 0) printf("TIE"); 
    if(state == 1) printf("VICTORY"); 
    if(state == -1) printf("DEFEAT");
    return 0;
}