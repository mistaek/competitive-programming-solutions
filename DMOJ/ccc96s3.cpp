/*
ccc96s3
ac
*/

#include <cstdio>
#include <vector>
#include <algorithm>
// one sec, gaming
using namespace std; 
int main(){
    int tc; scanf("%d", &tc);
    int n, k; vector<int> bits;
    while(tc--){
        bits.clear(); 
        scanf("%d %d", &n, &k);
        printf("The bit patterns are\n");
        for(int i = 0; i < k; i++) bits.push_back(0); 
        for(int i = 0; i < n-k; i++) bits.push_back(1); 
        do{
            for(int a : bits) printf("%d", 1-a); 
            printf("\n");
        }while (next_permutation(bits.begin(), bits.end()));
         

        if(tc) printf("\n");
    }
    return 0;
}