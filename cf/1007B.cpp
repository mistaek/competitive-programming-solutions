/*
1007B
BASICALLY EDITORIAL SOLUTION, IDK
*/

#include <iostream>
#include <numeric>

using namespace std; 

int f[100010] = {};

int p[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

long long calc(int* a)
{
    int g[8] = {};
    g[1] = f[a[0]]; 
    g[2] = f[a[1]]; 
    g[3] = f[gcd(a[0], a[1])]; 
    g[4] = f[a[2]];
    g[5] = f[gcd(a[0], a[2])]; 
    g[6] = f[gcd(a[1], a[2])]; 
    g[7] = f[gcd(a[0], gcd(a[1], a[2]))]; 
    long long ans1 = 0, ans2 = 0;
    for(int mask = 1; mask < (1<<6); ++mask){
        int x[3] = {}, cnt = 0;
        for(int i = 0; i < 6; ++i){
            if(mask & (1 << i)){
                ++cnt; 
                for(int j = 0; j < 3; ++j){
                    x[j] |= (1<<p[i][j]);
                }
            }
        }

        if (cnt & 1) {
            ans1 += g[x[0]] * g[x[1]] * g[x[2]];
            ans2 += g[x[0] | x[1]] * g[x[2]];
        } else {
            ans1 -= g[x[0]] * g[x[1]] * g[x[2]];
            ans2 -= g[x[0] | x[1]] * g[x[2]];
        }
    }
    return (ans1 + ans2 * 3 + g[7] * 2) / 6;
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    for(int i = 1; i <= 100000; ++i){
        for(int j = i; j <= 100000; j += i){
            ++f[j];
        }
    }


    int t; cin >> t; 
    while(t--){
        int a[3]; cin >> a[0] >> a[1] >> a[2];
        cout << calc(a) << "\n";
    }
    return 0;
}