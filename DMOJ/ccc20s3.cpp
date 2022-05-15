/*
ccc20s3
wip
*/

#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std; 
long long ans = 0;
long long nh, hh, mod = 1e9+9, hashbrown = 31;
long long nl, hl; 
string n, h;
//currently does not work
long long a(string aa, long long st, long long ed){
    long long mm = 0; 
    for(int i =st; i < ed; i++){
        char c = aa[i];
        long long n = c - 'a'+1;
        long long nn = n; 
        for(int i = 0; i < nn; i++){
            n*= hashbrown;
            n %= mod;
        }
        mm+= n;
        mm %= mod;
    }
    return mm % mod;
}
long long aaa(char c){
    long long mmm = c - 'a' +1; 
    long long nn = c-'a'+1;
    for(int i = 0; i < nn; i++){
        mmm *= hashbrown; 
        mmm%= mod; 
    }
    return mmm%mod;
}
int main(){
    cin >> n >> h;  
    nl = (int)n.length(); hl = (int) h.length(); 
    if(nl > hl) printf("0\n");
    
    nh = a(n, 0, nl);
    hh = a(h, 0, nl);
    if(nh == hh) ans++;
    for(int i = nl; i < hl; i++){
        hh += aaa(h[i]); 
        hh-= aaa(h[i-nl]);
        hh%= mod; 
        if(nh == hh) ans++;
    }
    printf("%d\n", ans);
    //note: pretty sure 31 as is equal to a b :/
    return 0;
}