//restart 
#include <cstdio>
#include <string>
#include <iostream>
#include <vector> 


typedef long long ll;

using namespace std; 

vector<int> coefs; vector<ll> b; int d, k;
long long evaluate(int a); void fill(int a, int idx); 

int main(){
    int tc; scanf("%d\n", &tc); 
    while(tc--){
        coefs.clear(); b.clear();  
        int deg; scanf("%d", &deg); deg++;
        while(deg--){int c; scanf("%d", &c); coefs.push_back(c);}
        scanf("%d\n%d\n", &d, &k);
        fill(1,0); 
        printf("%lld\n", b[k-1]); 
    }
    return 0; 
}
void fill(int a, int idx){
    ll val = evaluate(a); 
    for(int i = 0; i < a*d; i++){ b.push_back(val);if(idx >k) return; idx++;}  
    fill(a+1, idx); 
    
}
ll evaluate(int a){
    ll ans = 0; 
    for(int i = 0; i < (int)coefs.size(); i++){
        ll c, v = 1; 
        for(int j = 0; j < i; j++) v*= a;
        v *= coefs[i]; 
        ans += v;  
    }
    return ans;    
}