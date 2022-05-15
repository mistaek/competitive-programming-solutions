/*
ecoo20p4
is this easier than cpatcha?
ray
*/

#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std; 
//currently tle
#define MOD 1000000007;
typedef long long ll; 
map<string, vector<pair<string, int>>> functions; 

ll modit(ll n){
    ll ret = n; 
    ret %= MOD; 
    if(ret < 0) ret+= MOD; 
    return ret; 
}
ll execute(string fname, ll n ){
    ll ret = n; 
    for(pair<string, int> cmd : functions[fname]){
        if(cmd.first == "ADD") ret += cmd.second; 
        else if(cmd.first == "SUB") ret-= cmd.second; 
        else if(cmd.first == "MULT") ret*= cmd.second; 
        else ret = execute(cmd.first, ret);
        ret = modit(ret); 
    }
    return ret; 
}
int main(){
    int TC; 
    scanf("%d", &TC);

    while(TC--){
        functions.clear(); 
        ll n = 0; 
        int N; scanf("%d", &N); //num of commands
        while(N--){
            string cmd; cin >> cmd; 
            if(cmd == "ADD"){
                ll c; 
                scanf("%lld", &c); 
                n += c; 
                n = modit(n); 
            }
            else if(cmd == "SUB"){
                ll c; scanf("%lld", &c); 
                n-= c; 
                n = modit(n); 
            }
            else if(cmd == "MULT"){
                ll c; scanf("%lld", &c); 
                n*= c; 
                n = modit(n);  
            }
            else if(cmd == "FUN"){
                //contrary to popular belief, this is not fun!
                string name; cin >> name; 
                while(cin >> cmd){
                    N--;
                    if(cmd == "END") break; 
                    else{
                        ll c; scanf("%lld", &c); 
                        functions[name].push_back(make_pair(cmd, c));
                    }
                }
            }
            else if(cmd == "CALL"){
                string fname; cin >> fname; 
                n = execute(fname, n);
            }
        }
        printf("%lld\n", modit(n)); 
    }
    return 0;
}