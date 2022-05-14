/*
1622B
WIP
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n); 
        vector<pair<int, int>> p, f, l;
        for(int i = 0; i < n; i++){
            int in; scanf("%d", &in); 
            p.push_back({in, i});
        }
        for(int i = 0; i < n; i++){
            int r; 
            scanf("%1d", &r);
            if(r) f.push_back(p[i]);
            else l.push_back(p[i]);
        }
        p.clear();
        sort(f.begin(), f.end()); 
        sort(l.begin(), l.end());
        for(int i = 0; i < f.size(); i++){
            p.push_back({f[i].second, n - f.size() + 1 + i}); 
        }
        for(int i = 0; i < l.size(); i++){
            p.push_back({l[i].second, i+1});
        }
        sort(p.begin(), p.end()); 
        for(int i = 0; i < p.size(); i++){
            if(i) printf(" %d", p[i].second); 
            else printf("%d", p[i].second);
        }
        printf("\n");

    }
    return 0;
}