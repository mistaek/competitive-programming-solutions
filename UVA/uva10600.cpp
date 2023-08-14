/*
uva 10600
ray
AC
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std; 

class ufds{
    private: 
    vector<long long> p, r; 
    long long s; 
    public: 
    ufds (long long n){
        p.assign(n+1, 0); r.assign(n+1,0); 
        for(long long i = 0; i < n+1; i++) p[i] = i; 
        s = n;
    }
    long long fs(long long a){ return (p[a] == a) ? a : p[a] = fs(p[a]);}
    bool ss(long long a, long long b){return fs(a) == fs(b);}
    void ms(long long a, long long b){
        if(ss(a, b)) return; 
        s--; 
        long long x = fs(a),y = fs(b);
        if(r[x] > r[y]) p[y] = x; 
        else{
            p[x] = y; 
            if(r[x] == r[y]) r[y]++;
        } 
    }
    long long ns(){return s;}
};

int main(){
    long long t; scanf("%lld", &t); 
    while(t--){
        long long n, m; scanf("%lld %lld", &n, &m);
        vector<pair<long long, pair<long long, long long>>> el;
        vector<long long> inmst; 
        for(int i = 0; i < m; i++){
            long long a, b, c; scanf("%lld %lld %lld", &a, &b, &c); 
            el.push_back({c, {a, b}});
        }
        sort(el.begin(), el.end());

        ufds mst(n); 
        long long s1 = 0; 

        for(long long i = 0; i < m; i++){
            pair<long long, pair<long long, long long >> e = el[i];
            if(!mst.ss(e.second.first, e.second.second)){
                mst.ms(e.second.first, e.second.second); 
                s1 += e.first; 
                inmst.push_back(i);
            }
        }


        long long s2 = 1e9; 
        for(long long i : inmst){
            ufds smst(n); 
            long long tot2 = 0; 
            for(int j = 0; j < m; j++){
                if(i == j) continue; 
                if(!smst.ss(el[j].second.first, el[j].second.second)){
                    smst.ms(el[j].second.first, el[j].second.second); 
                    tot2 += el[j].first; 
                } 
            }
            if(smst.ns() == 1) s2 = min(tot2, s2);
        }

        printf("%lld %lld\n", s1, s2);

    }
    return 0;
}