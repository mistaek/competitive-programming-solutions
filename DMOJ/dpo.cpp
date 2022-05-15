/*
dp o
wip
*/

#include <cstdio>
#include <bitset> 
//will solve tomorrow, bitset dp is :(
#define MOD 1e9 + 7;
using namespace std; 

int n; 
map<pair<bitset<21>, int>, long long> dp; 
long long arr[21][21]; 

int iterate(bitset<21> bits, int man){
    if(man == n+1) return; 
    if(dp.count({bits, man})) return; 
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[man][i]){

        }
    }

    
}

int main(){
    scanf("%d", &n); 

    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    } 

    
    bitset<21> empty; empty.reset(); 
    
    dp[{empty, 0}] = 1; 
    
    iterate(empty, 1); 
    return 0;
}