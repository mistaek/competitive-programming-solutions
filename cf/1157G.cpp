    /*
    1157G
    */
     
    #include <iostream>
    #include <vector>
    #include <bitset>
     
    using namespace std; 
     
    int main(){
        ios_base::sync_with_stdio(false); 
        cin.tie(0); cout.tie(0); 
     
        int n, m; cin >> n >> m; 
        vector<vector<bool>> grid(n, vector<bool>(m, 0)); 
     
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int x; cin >> x; 
                grid[i][j] = x;
            }
        }
     
        bool pos = true;
        for(int c = -1; c < m; ++c){
            pos = true; 
            vector<vector<bool>> copy = grid; 
            //these columns are zeroes (first row)
            vector<bool> flippedRows(n, 0); vector<bool> flippedCols(m, 0); 
            for(int i = 0; i <m ; ++i){
                if(i <= c && copy[0][i] == 1){
                    //flip this column
                    for(int j = 0; j <n; ++j){
                        copy[j][i] = !copy[j][i];
                    }
                    flippedCols[i] = true; 
                }
                else if(i > c && copy[0][i] == 0){
                    for(int j = 0; j <n; ++j){
                        copy[j][i] = !copy[j][i];
                    }
                    flippedCols[i] = true; 
                }
            }
     
            int prev;
            for(int i = 1; i < n; ++i){
                prev = copy[i-1][m-1]; 
                if(!pos) break; 
                for(int j = 0; j <m;++j){
                    if(copy[i][j] < prev){
                        pos = false; 
                        break; 
                    }
                    prev = copy[i][j];
                }
                if(pos){
                    //might as well
                    if(copy[i-1][m-1] == 0 && copy[i][0] == 1){
                        flippedRows[i] = true; 
                        for(int j = 0; j < m; ++j) copy[i][j] = !copy[i][j]; 
                    }
                    continue; 
                }
                pos = true; //try flip
                prev = copy[i-1][m-1];
                flippedRows[i] = true; 
                for(int j = 0; j <m;++j){
                    copy[i][j] = !copy[i][j];
                }
                for(int j = 0; j < m; ++j){
                    if(copy[i][j] < prev){
                        pos = false; 
                        break; 
                    }
                    prev = copy[i][j];
                }
            }
            if(!pos){
                continue; 
            }
            else{
                cout << "YES\n"; 
                for(int i = 0; i < n; ++i) cout << (int)flippedRows[i];
                cout << "\n";  
                for(int j = 0; j < m; ++j) cout << (int)flippedCols[j];
                cout << "\n"; 
                break;
            }
        }
        if(!pos){
            cout << "NO\n";
        }
     
     
     
        
        return 0;
    }