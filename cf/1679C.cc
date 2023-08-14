/*
1679C
AC
*/

#include <cstdio>
#include <set> 
#include <algorithm>
#include <vector>

using namespace std; 

int main(){
    int n, q; scanf("%d %d", &n, &q); 
    set<int> r, c; 
    vector<int> rcnt(n+1, 0), ccnt(n+1, 0);
    for(int i = 0; i <= n; i++){
        r.insert(i+1); c.insert(i+1); 
    }
    for(int i = 0; i < q; i++){
        int t; scanf("%d", &t); 
        if(t == 1){
            int x, y; scanf("%d %d", &x, &y);
            r.erase(x); c.erase(y); 
            rcnt[x]++; ccnt[y]++;
        }
        else if(t == 2){
            int x, y; scanf("%d %d", &x, &y);
            rcnt[x]--; ccnt[y]--; 
            if(rcnt[x] == 0) r.insert(x); 
            if(ccnt[y] == 0) c.insert(y); 
        }
        else if(t == 3){
            int x1, x2, y1, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2); 
            auto rit = r.lower_bound(x1), cit = c.lower_bound(y1); 
            
            if( *rit > x2 || *cit > y2) printf("Yes\n"); 
            else printf("No\n");
        }
    }
    return 0;
}