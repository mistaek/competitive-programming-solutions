/*
1774D
AC
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n, m, tot=0; cin >> n >> m;
        int a[n][m] = {};
        vector<pair<int, int>> cnt;  
        for(int i = 0; i < n; i++){
            int icnt = 0; 
            for(int j = 0; j < m; j++){
                cin >> a[i][j]; 
                icnt += a[i][j]; 
            }
            tot += icnt; 
            cnt.push_back({icnt, i});
        }
        if(tot % n){
            cout << "-1\n"; 
            continue; 
        }

        sort(cnt.begin(), cnt.end());
        
        int i =0, j = n-1; 
        int opcount = 0;
        vector<pair<pair<int, int>, int>> ops; 
        while(i <j){
            
            for(int k = 0; k < m; k++){
                if(cnt[i].first == tot/n){
                    i++; 
                    break;
                } 
                if(cnt[j].first == tot/n){
                    j--;
                    break;
                }
                if(a[cnt[i].second][k] == 0 && a[cnt[j].second][k] == 1){
                    opcount++;
                    ops.push_back({{cnt[i].second +1, cnt[j].second +1}, k+1});
                    swap(a[cnt[i].second][k], a[cnt[j].second][k]);
                    cnt[i].first++;
                    cnt[j].first--;
                }
            }
        }
        cout << opcount << "\n";
        for(i = 0; i < opcount; i++){
            cout << ops[i].first.first << " " << ops[i].first.second << " " << ops[i].second << "\n";
        }

    }
    return 0;
}