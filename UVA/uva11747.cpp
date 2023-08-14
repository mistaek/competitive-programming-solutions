/*
UVa 11747
Ray
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
        ufds (long long i){
            p.assign(i, 0); r.assign(i, 0); 
            for(long long n = 0; n < i; n++) p[n] = n; 
            s = i; 
        }
        long long fs(long long n){ return (p[n] == n) ? n : p[n] = fs(p[n]);}
        bool ss(long long a, long long b){return fs(a) == fs(b);}
        long long ns(){return s;}
        void ms(long long a, long long b){
            if(ss(a, b)) return; 
            int x = fs(a), y = fs(b); 
            if(r[x] > r[y]) p[y] = x;
            else{
                p[x] = y; 
                if(r[x] == r[y]) r[y]++;
            } 
        }
};

int main(){
    long long n, m; 
    while(scanf("%lld %lld", &n, &m), n){
        ufds ug(n);
        vector<pair<long long, pair<long long, long long>>> el; 
        for(long long i = 0; i < m; i++){
            long long a, b, c; scanf("%lld %lld %lld", &a, &b, &c);
            el.push_back({c, {a,b}}); 
        }
        vector<long long> out; 
        sort(el.begin(), el.end()); 

        for(pair<long long, pair<long long, long long>> e : el){
            if(!ug.ss(e.second.first, e.second.second)){
                ug.ms(e.second.first, e.second.second); 
            }
            else{
                out.push_back(e.first); 
            }
        }

        sort(out.begin(), out.end()); 

        if(out.size() == 0) printf("forest"); 
        else{
            for(auto it = out.begin(); it != out.end(); it++) {
                (it == out.begin()) ? printf("%lld", *it) : printf(" %lld", *it); 
            }
        }
        printf("\n");
    }
    return 0;
}