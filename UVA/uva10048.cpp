/*
UVa 10048
Ray
AC
*/

//this is mst version, apparently floyd warshall works too

#include <cstdio>
#include <vector> 
#include <algorithm>
#include <queue>

using namespace std; 

class ufds{
    private: 
    vector<long long> p, r; 

    public: 
    ufds (long long n){
        p.assign(n+1, 0); r.assign(n+1,0); 
        for(long long i = 0; i < n+1; i++) p[i] = i; 
    }
    long long fs(long long a){ return (p[a] == a) ? a : p[a] = fs(p[a]);}
    bool ss(long long a, long long b){return fs(a) == fs(b);}
    void ms(long long a, long long b){
        if(ss(a, b)) return; 
        long long x = fs(a),y = fs(b);
        if(r[x] > r[y]) p[y] = x; 
        else{
            p[x] = y; 
            if(r[x] == r[y]) r[y]++;
        } 
    }
};
int main(){
    long long c, s, q; long long ccount = 1; 
    while(scanf("%lld %lld %lld", &c, &s, &q), c){
        if(ccount != 1) printf("\n");
        printf("Case #%d\n", ccount++);
        vector<pair<long long, pair<long long, long long>>> el; 
        for(long long i = 0; i< s; i++){
            long long x, y, z; scanf("%lld %lld %lld", &x, &y, &z); 
            el.push_back({z, {x, y}}); 
        }

        sort(el.begin(), el.end()); 
        ufds mst(c+1); 
        vector<pair<long long, long long>> adjl[c+1]; 
        for(pair<long long, pair<long long, long long>> e : el){
            if(!mst.ss(e.second.first, e.second.second)){
                mst.ms(e.second.first, e.second.second);
                adjl[e.second.first].push_back({e.second.second,e.first});
                adjl[e.second.second].push_back({e.second.first,e.first});
            }
        }

        for(int i = 0; i < q; i++){
            long long fir, sec; scanf("%lld %lld", &fir, &sec); 
            if(!mst.ss(fir, sec)) printf("no path\n"); 
            else{
                vector<long long> dist(c+1, -1); 
                queue<long long> q; q.push(fir); dist[fir] = 0; 
                while(!q.empty()){
                    long long v = q.front();
                    q.pop(); 
                    for(pair<long long, long long> nxt : adjl[v]){
                        if(dist[nxt.first] == -1){
                            dist[nxt.first] = max(dist[v], nxt.second);
                            q.push(nxt.first); 
                        }
                    }  
                }
                printf("%lld\n", dist[sec]);
            }
        }
        


    }
    return 0;
}