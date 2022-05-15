#include <cstdio>
#include <vector>
#include <cmath>
typedef double db; 
using namespace std; 
vector<pair<int, int>> list; 
int check(int k); 
int main(){
    int k; 
    while(scanf("%d", &k) != EOF){
        list.clear(); 
        printf("%d\n", check(k));
        for(auto it = list.begin(); it!= list.end(); it++){
            printf("1/%d = 1/%lld + 1/%lld\n", k, it->first, it -> second); 
        } 
    }
    return 0;   
}

int check(int k){
    int ans = 0; 
    int x = k *(k+1); 
    while(x >= k*2){
        int y = (k*x)/(x-k);
        if((x*y)/(x+y) ==k){ ans++; list.push_back(make_pair(x, y)); }
        x--; 
    } 
    return ans; 
}