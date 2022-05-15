/*
Atcoder DPA Frog 1
[NAME]
AC
*/

#include <cstdio>
#include <cstring>

#define min(a, b) ((a < b)? a : b)
using namespace std; 

int num, memo[100005], rocks[100005];//BRUH I FORGOT A ZERO ARE U KIDDING ME

int abs(int a){
    if(a > 0) return a; 
    else return -a; 

}

int main(){
    memset(memo, -1, sizeof(memo));
    scanf("%d", &num);  
    for(int i = 0; i < num; i++){ 
    	scanf("%d", &rocks[i]);
    }
    memo[0] = 0;
    for(int i = 1; i < num; i++){
        memo[i] = memo[i-1] + abs(rocks[i] - rocks[i-1]); //jump 1
        if(i > 1){
            memo[i] = min(memo[i-1] + abs(rocks[i] - rocks[i-1]), memo[i-2] + abs(rocks[i] - rocks[i-2])); //account for 2 jump
        }
    }
    printf("%d\n", memo[num-1]);
    return 0;
}
