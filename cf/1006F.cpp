/*
1006F
AC, new tech
*/

#include <iostream>
#include <map>
using namespace std; 

long long n, m, k; 
long long grid[20][20] = {};
map<long long, long long> cnt[20][20];


int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m >> k; 
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
        }
    }

    int f = (n + m-2)/2, s = (n+m-2) - f; // make this many moves
    //FIRST HALF
    for(int i = 0; i < (1 << f); ++i){
        long long curx = 0, cury = 0;
        long long curxor = grid[0][0];
        bool oob = false; 
        for(int j = 0; j < f; ++j){
            if(i & (1 << j)) ++curx; 
            else ++cury;
            if(curx >= n || cury >=m){
                oob = true; 
                break; 
            }
            curxor ^= grid[curx][cury];
        }
        if(!oob){
            //cout << curx << " " << cury << " " << curxor << "\n";
            ++cnt[curx][cury][curxor];
        }
    }
    
    //cout << "\n";
    //SECOND HALF 
    long long ans = 0;
    for(int i = 0; i < (1 << s); ++i){
        long long curx = n-1, cury = m-1, curxor = 0; 
        bool oob = false; 
        for(int j = 0; j < s; ++j){
            curxor ^= grid[curx][cury];
            if(i & (1 << j)) --curx; 
            else --cury; 
            if(curx < 0 || cury < 0){
                oob = true; 
                break; 
            }
        }
        if(!oob){
            //cout << curx << " " << cury << " " << (k^curxor) << "\n";
            ans += cnt[curx][cury][k ^ curxor];
        }
    }
    cout << ans << "\n";
    return 0;
}