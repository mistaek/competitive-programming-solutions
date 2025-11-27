#include <iostream>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int k; cin >> k; 
    vector<int> row, col; 
    for(int i = 1; i <= k; ++i){
        int r; cin >> r; 
        for(int j = 0; j < r; ++j){
            row.push_back(i); 
        }
    }
    for(int i = 1; i <= k; ++i){
        int r; cin >> r; 
        for(int j = 0; j < r; ++j){
            col.push_back(i); 
        }
    }
    int n = row.size(), m = col.size(); 
    vector<vector<int>> grid(n, vector<int>(m, 0)); 
    
    vector<int> rowneed(n, m/2 + 1), colneed(m, n/2 + 1); 
    vector<int> rowrem(n, m), colrem(m, n);
    // fixed 
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
           if(row[i] == col[j]){
            grid[i][j] = row[i];
            rowneed[i]--;
            rowrem[i]--;
            colneed[j]--;
            colrem[j]--;
           } 
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] != 0) continue; 
            
            if(colneed[j] == 0 || (rowneed[i] && rowneed[i] == rowrem[i])){
                grid[i][j] = row[i]; 
                rowneed[i]--;
                rowrem[i]--;
                colrem[j]--; 
            }
            else if(rowneed[i] == 0 || (colneed[j] && colneed[j] == colrem[j])){
                grid[i][j] = col[j];
                colneed[j]--;
                rowrem[i]--;
                colrem[j]--;
            }
            else if(row[i] < col[j]){
                grid[i][j] = row[i]; 
                rowneed[i]--;
                rowrem[i]--;
                colrem[j]--; 
            }
            else{
                grid[i][j] = col[j];
                colneed[j]--;
                rowrem[i]--;
                colrem[j]--;
            }
        }
    }

    bool pos = true; 
    for(int i = 0; i < n; ++i){
        if(rowneed[i] > 0) pos = false; 
    }
    for(int i = 0; i < m; ++i){
        if(colneed[i] > 0) pos = false; 
    }
    if(pos){
        cout << "YES\n"; 
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(j) cout << " "; 
                cout << grid[i][j]; 
            }
            cout << "\n"; 
        }
    }
    else cout << "NO\n"; 
    
    return 0;
}