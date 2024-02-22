/*
1900C
*/

#include <iostream>
#include <vector>

using namespace std; 

vector<char> dir; 
vector<pair<int, int>> chld; 

int solve(int u){
    if(u == 0) return 1e7; 
    if(chld[u].first == 0 && chld[u].second == 0) return 0;

    if(dir[u] == 'U') return 1 + min(solve(chld[u].first), solve(chld[u].second));
    if(dir[u] == 'R') return min(1 + solve(chld[u].first), solve(chld[u].second));
    if(dir[u] == 'L') return min(solve(chld[u].first), 1 + solve(chld[u].second));
}
int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        dir = vector<char>(n+1); 
        chld = vector<pair<int, int>>(n+1);

        for(int i = 1; i <= n; i++){
            cin >> dir[i]; 
        }
        for(int i = 1; i <= n; i++){
            cin >> chld[i].first >> chld[i].second;
        }

        cout << solve(1) << "\n"; 

    }
    return 0;
}