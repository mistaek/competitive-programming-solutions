#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std; 

bool ans = false; 
int nums[12] = {}, total, n; 

set<vector<int>> printed; 
void printAns(int mask, int bits){
	ans = true; 
    vector<int> putinset; 
	bits--; 
    for(int i = 0; i < n; i++){
        if(mask & (1 << i)){
            putinset.push_back(nums[i]); 
        }

    }
    if(printed.count(putinset)) return; 
    printed.insert(putinset); 
    for(int i = 0; i < n; i++){
        if(mask & (1 << i)){
            (bits) ? printf("%d+", nums[i]) : printf("%d\n", nums[i]);   
            bits--;

        }

    }
}

void backtrack(int total, int amnt, int mask, int idx, int bits){
    if(amnt == total){printAns(mask, bits); return;}
    if(idx == n) return; 
    if(amnt + nums[idx] <= total){
        backtrack(total, amnt + nums[idx], mask | (1 << idx), idx+1, bits+1); 
    }
    backtrack(total, amnt, mask, idx+1, bits); 
}

int main(){
    while(scanf("%d", &total), total){
        printed.clear();
        ans = false; 
        scanf("%d", &n);
        for(int i =0; i < n; i++){
            scanf("%d", &nums[i]); 
        }
        int mask = 0; 
        printf("Sums of %d:\n", total);
        backtrack(total, 0, 0, 0, 0); 
        if(!ans) printf("NONE\n"); 
        
    }
    return 0; 
}