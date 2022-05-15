/*
UVa 11631
Ray
AC
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring> 

using namespace std; 




class ufds{
    private: 
        vector<int> ds, r; 
        int s; 
    public: 
        ufds(int n){
            ds.assign(n+1, 0); r.assign(n+1, 0); 
            for(int i = 0; i < n+1; i++) ds[i] = i; 
            s = n; 
        }

        int fs(int n){
            return (ds[n] == n) ? n : ds[n] = fs(ds[n]);
        }

        bool ss(int a, int b){ return fs(a) == fs(b); }

        void ms(int a, int b){
            if(!ss(a, b)){
                s--; 
                int x = fs(a), y = fs(b); 
                if(r[y] > r[x]) ds[x] = y; 
                else if(r[x] > r[y]) ds[y] = x; 
                else{
                    ds[y] = x; 
                    r[x]++; 
                }
            }
        }

        int ns(){ return s; }
};

int main(){
    int m, n; 
    while(scanf("%d %d", &m, &n), m){
        ufds lights(m);
        vector<pair<int, pair<int, int>>> el;
        long long total = 0; 
        for(int i = 0; i < n; i++) {
            int a, b, c; scanf("%d %d %d", &a, &b, &c);
            el.push_back({c, {a, b,}});
            total+= c; 
        } 
        sort(el.begin(), el.end()); 
        long long tsave = 0; 
        for(pair<int, pair<int, int>> e : el){
            if(!lights.ss(e.second.first, e.second.second)){
                lights.ms(e.second.first, e.second.second); 
                tsave += e.first; 
            }
            if(lights.ns() == 1) break; 
        }

        printf("%d\n", total - tsave); 
    }    
}