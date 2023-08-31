/*
1864
*/
//needed io optimization, doesnt work with iostream???

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        vector<vector<int>> a(n, vector<int>(n));
        vector<vector<int>> l(2, vector<int>(n, 0)), r(2, vector<int>(n, 0)),d(2, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%1d", &a[i][j]);
                l[0][j] = l[1][j]; 
                r[0][j] = r[1][j]; 
                d[0][j] = d[1][j];
                l[1][j] = r[1][j] = d[1][j] = 0; 
            }
            for(int j = 0; j < n; j++){
                if((a[i][j] + d[0][j]) % 2){
                    ans++;
                    if(j - 1 >= 0){
                        l[1][j-1]++;
                        d[1][j-1]++;
                    }
                    d[1][j]++;
                    if(j+1 < n){
                        r[1][j+1]++;
                        d[1][j+1]++;
                    }
                }
                if(j-1 >= 0){
                    r[1][j] += r[0][j-1];
                    d[1][j] += r[0][j-1]; 
                }
                d[1][j] += d[0][j];
                if(j+1 < n){
                    l[1][j] += l[0][j+1]; 
                    d[1][j] += l[0][j+1];
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}