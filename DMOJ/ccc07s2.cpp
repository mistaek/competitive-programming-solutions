/*
ccc 07s2
ac - im rart
*/
#include <cstdio>
#include <algorithm>
using namespace std; 
//numbers are low enough for o(n^2)
long long boxes[1001][3], products[1001][3];

bool test(int b, int p){
    for(int j = 0; j < 3; j++){
        if(boxes[b][j] < products[p][j]){
            return false;
        }
    }
    return true;
}

int main(){
    int n; scanf("%d", &n); 
    for(int i = 0; i < n; i++){ 
        scanf("%lld %lld %lld", &boxes[i][0], &boxes[i][1], &boxes[i][2]); 
        sort(boxes[i], boxes[i] +3);
    }
    int m; scanf("%d", &m);
    for(int i = 0; i < m; i++){ 
        scanf("%lld %lld %lld", &products[i][0], &products[i][1], &products[i][2]); 
        sort(products[i], products[i]+3);
    }

    for(int i = 0; i < m; i++){//test product m 
        long long ans = 1e15;
        for(int j = 0; j < n; j++){ // test box j
            if(test(j, i)) ans = min(ans, (boxes[j][0] * boxes[j][1] * boxes[j][2])); //if fits, find volume and compare
        }
        if(ans == 1e15) printf("Item does not fit.\n");
        else printf("%lld\n", ans); 
    }
    
    return 0;
}

/*
1
2 3 4 
1
4 3 2 
*/