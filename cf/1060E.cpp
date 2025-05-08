/*
1060E
AC, got lost in the sauce
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

long long ans = 0;

struct VD{
    long long stsize = 0; 
    long long sizeOdd = 0;
    long long distOdd = 0; 
    long long distEven = 0;
    long long sizeEven = 0;
};
vector<vector<int>> g; 
vector<int> p; 
vector<VD> d; //data: d[0] i

void solve(int i){
    d[i].stsize = d[i].sizeEven = 1; 
    for(auto c : g[i]){
        if(c != p[i]){
            p[c] = i; 
            solve(c);

            d[i].distOdd += d[c].distEven + (d[c].sizeEven); // all even paths: add 1
            d[i].sizeOdd += d[c].sizeEven; 
            d[i].distEven += d[c].distOdd; // all odd paths: can skip straight to i 
            d[i].sizeEven += d[c].sizeOdd; 
            d[i].stsize += d[c].stsize;
        }
    }   
    long long contrib = 0;
    
    //cout << "Vertex " << i << "\n"; 
    //cout << d[i].stsize << " " << d[i].sizeEven << " " << d[i].sizeOdd << " " << d[i].distEven << " " << d[i].distOdd << "\n";
    // do one more loop after all children have been resolved
    int cc = 0;
    for(auto c : g[i]){
        if(c != p[i]){
            ++cc; 
            long long remOdd = d[i].sizeOdd - d[c].sizeEven; // number of vertices NOT in subtree c which have odd distance to i
            //we subtract d[c].even since anything with even dist to c is odd to i 
            long long remEven = d[i].sizeEven - d[c].sizeOdd; //same thing

            long long distToRootOdd = d[i].distOdd - d[c].sizeEven - d[c].distEven; // total distance from remOdd to i 
            contrib += d[c].stsize * distToRootOdd + remOdd * (d[c].distEven + d[c].distOdd); //all odds have even distance to c, so go to c and then take shortest routes
            
            long long distToRootEven = d[i].distEven - d[c].distOdd; 

            //cout << "Viewing subtree " << c << "\n"; 
            //cout << remOdd << " " << remEven << " " << distToRootOdd << " " << distToRootEven << "\n";

            contrib += d[c].stsize * distToRootEven; // all evens go to root
            contrib += remEven * d[c].distOdd; // then, can skip straight to odds of c, since path to root is even
            contrib += remEven * (d[c].distEven + d[c].sizeEven); //for evens, take a + 1 somewher      
        }
    }
    if(cc > 1){
        contrib += d[i].distEven + d[i].distOdd; 
        ans += contrib/2; 
        //cout << i << " " << contrib << " " << contrib/2 << "\n"; 
    }
    else{
        ans += contrib; 
        //cout << i << " " << contrib << "\n";
    }
}
int main(){
    int n; cin >> n; 
    g = vector<vector<int>>(n); 
    p = vector<int>(n, -1); 
    d = vector<VD>(n);
    for(int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v; 
        --u, --v; 
        g[u].push_back(v); 
        g[v].push_back(u);
    }

    solve(0); //arbitrary
    cout << ans << "\n";
    return 0;
}