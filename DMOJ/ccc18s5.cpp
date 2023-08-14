/*
ccc 18 s5
ray
AC
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std; 

//augh brain ded
//forgot about case where m = n lol 
//be more careful!
class UFDS{
    private: 
    
    vector<long long> p, r; 
    long long s; 
    public: 
    UFDS(long long n){
        p.assign(n+1, 0); r.assign(n+1, 0);
        for(long long i = 0; i <= n; i++) p[i] = i; 
        s = n;
    }
    long long fs(long long a){return (p[a] == a) ? a : p[a] = fs(p[a]);}
    bool ss(long long a, long long b){return (fs(a) == fs(b));}
    void ms(long long a, long long b){
        if(!ss(a, b)){
            s--;
            long long x = fs(a); long long y = fs(b); 
            if(r[x] > r[y]) p[y] = p[x]; 
            else{
                p[x] = p[y]; 
                if(r[x] == r[y]) r[y]++;
            }
        }
    }
    long long ns(){return s;}
};
int main(){
    long long n, m, p, q; scanf("%lld %lld %lld %lld", &n, &m, &p, &q);

    vector<pair<pair<long long,long long>, pair<long long,long long>>> el;

    long long tt = 0;; 

    for(long long i = 0; i < p; i++){
        long long a, b, w; 
        scanf("%lld %lld %lld", &a, &b, &w); 
        tt+= (n* w);
        //travel amongst cities
        el.push_back(make_pair(make_pair(w,1), make_pair(a, b))); 
    }
    for(long long i = 0; i < q; i++){
        long long a, b, w; 
        scanf("%lld %lld %lld", &a, &b, &w); 
        tt +=  (m*w); 
        //travel amongst planets
        el.push_back(make_pair(make_pair(w, 0), make_pair(a, b))); 
    }

    
    sort(el.begin(), el.end());

    UFDS mstp(n), mstc(m); 
    long long ct = 0;
    
    for(pair<pair<long long,long long>, pair<long long, long long>> e : el){
        if(e.first.second == 0){ 
            //if it is among planets
            if(!mstp.ss(e.second.first, e.second.second)){
                ct += (mstc.ns() * e.first.first); 
                mstp.ms(e.second.first, e.second.second);
            }
        }
        else if(e.first.second == 1){
            //if it is among cities
            if(!mstc.ss(e.second.first, e.second.second)){
                ct += (mstp.ns() * e.first.first); 
                mstc.ms(e.second.first, e.second.second);
            }
        }
    }

    printf("%lld", tt - ct);

   
    return 0;
}