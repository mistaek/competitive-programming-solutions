// BIT Test
// 1 is stored in 1 
// 1-2 is stored in 2 
// 3-3 is stored in 3 
// 1 - 4 is stored in 4 
// 5-5 is stored in 5 
// 5-6 is stored in 6 
// 5-7 is stored in 7 
// 1 - 8 is stored in 8
// pee is stored in the bladder
#include <cstdio>
#include <vector>


using namespace std; 

typedef long long ll; 
ll LSOne(ll n){return (n & (-n));}

class FTree{
    private: vector<ll> ft; 
    public: FTree(ll n){ft.assign(100001, 0); }
    ll rsq(ll b){
        ll ans = 0; 
        while(b){
            ans += ft[b];
            b -= LSOne(b); 
        }
        return ans; 
    }
    ll rsq(ll a, ll b){
        return rsq(b) - ((a == 1) ? 0 : rsq(a-1)); 
    }
    void adjust(ll pos, int dif){
        for(; pos < (ll)ft.size(); pos += LSOne(pos)){
            ft[pos] += dif; 
        }
    }
   

}; 

int main(){
    ll n, m; scanf("%lld %lld", &n, &m); 
    ll arr[n]; 
    FTree bit(n), count(n); 
    for(int i =0; i < n; i++){
        scanf("%lld", &arr[i]); 
        bit.adjust(i+1, arr[i]);
        count.adjust(arr[i], 1);
    }

    for(int i = 0; i < m; i++){
        char t; 
        scanf(" %c", &t);
        if(t == 'C'){
            ll pos, val; 
            scanf(" %lld %lld", &pos, &val); 
            ll dif = val - arr[pos-1]; 
            bit.adjust(pos, dif); 
            count.adjust(val, 1); 
            count.adjust(arr[pos-1], -1);
            arr[pos-1] = val; 
        } 
        else if(t == 'S'){
            ll n1, n2; 
            scanf("%lld %lld", &n1, &n2); 
            printf("%lld\n", bit.rsq(n1, n2)); 
    
        }
        else{
            ll n1; 
            scanf("%lld", &n1); 
            printf("%lld\n", count.rsq(n1));
        }
    }
    return 0; 
}