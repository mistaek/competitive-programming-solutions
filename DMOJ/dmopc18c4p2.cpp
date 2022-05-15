/*
dmopc18c4p2
ac - watch the bounds
*/

#include <cstdio>
#include <algorithm>
//bitset can make this WAY faster!
using namespace std; 
int main(){
    int n; scanf("%d", &n); 
    int arr[n], reachable[500000], sum = 0;
    reachable[0] = 1; 
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
        for(int j = 500000; j >= arr[i]; j--){
            if(reachable[j-arr[i]]) reachable[j] = 1; 
        }
    }
    int best = 1e9; 
    for(int i = 0; i < 500000; i++){
        if(reachable[i]){
            best = min(abs((2 * i) - sum), best); 
        }
    } 
    printf("%d\n", best);

    return 0;
}