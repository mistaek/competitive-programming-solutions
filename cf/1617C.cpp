/*
1617C
ac - fuzzy mind
*/

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std; 
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n); 
        int a, p[n+1] = {};
        vector<int> v; 
        for(int i = 1; i <= n; i++){
            scanf("%d", &a);
            if(1 <= a && a <= n && p[a] == 0){
                p[a] = 1; 
            }
            else v.push_back(a);
        }
        sort(v.begin(), v.end());
        int it = 0;
        bool t = true; 
        for(int i = 1; i <= n; i++){
            if(p[i] == 0){
                if(v[it] - i <= i) t = false; 
                else it++;
            }
        }
        if(t) printf("%d\n", v.size()); 
        else printf("-1\n");
    }
    return 0;
}