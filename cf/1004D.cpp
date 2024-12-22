/*
1004D
AC, clever brute force
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

vector<long long> cnt;

/*void test(){
    srand(time(0));
    while(true){
        long long tx = rand() % 4 + 1, ty = rand() % 4+1; 
        long long px = rand() % tx + 1, py = rand() % ty + 1; 
        int t = tx * ty;
        cnt = vector<long long>(t+1, 0);
        vector<vector<long long>> grid(ty, vector<long long>(tx)); 
        for(int i = 1; i <= tx; ++i){
            for(int j = 1; j<= ty; ++j){
                cnt[abs(i - px) + abs(j - py)]++;
                grid[j-1][i-1] = abs(i - px) + abs(j - py);
            } 
        }

        bool possible = false; 
        long long x1 = -1, x2 = 0, y1 = 0 , y2= 0 , b = 0, x, y;
        for(int i = 1; i < t; ++i){
            if(x1 == -1 && cnt[i] != 4*i) x1 = i-1;
            if(cnt[i] != 0) b = i; 
        }
        if(x1 == -1) x1 = 0;

        for(x = x1 + 1; x * x <= t; ++x){
            if(t % x == 0){
                y = t/x; 
                
                x2 = x - x1 - 1;
                y2 = b - x2; 
                y1 = y - y2 - 1; 
                //cout << "test " << x << " " << y << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << b << "\n";

                if(y1 < 0 || y2 < 0) continue;
                vector<long long> dup = cnt; 
                long long total = t; 
                bool breakcond = false; 
                for(int i = 1; i <= x; ++i){
                for(int j  =1; j <= y; ++j){
                        long long mandist = abs(i - x1 -1) + abs(j - y1 - 1);
                        if(dup[mandist] == 0){
                            breakcond = true; 
                            break; 
                        }
                        
                        --dup[mandist];
                        --total; 
                }
                if(breakcond) break; 
                }
                if(total) continue; 
                possible = true; 
                break; 
            }
        }
        if(!possible){
            cout << t << "\n"; 
            for(int i = 0; i < t; ++i){
                for(int j = 0; j < cnt[i]; ++j){
                    cout << i << " "; 
                }
            }
            cout << "\n"; 
            cout << tx << " " << ty << " " << px << " " << py << "\n";
            for(int i = 0; i < ty; ++i){
                for(int j = 0; j < tx; ++j){
                    cout << grid[i][j] << " "; 
                }
                cout << "\n";
            }
            cout << "\n";
            return; 
        }
    }
}
*/
int main(){
    //test(); 
    //return 0;
    int t; cin >> t; 
    cnt = vector<long long>(t+1, 0);
    for(int i = 0; i < t; ++i){
        int a; cin >> a; 
        ++cnt[a];
    }

    if(cnt[0] != 1){
        cout << "-1\n"; 
        return 0;
    }

    bool possible = false; 
    long long x1 = -1, x2 = 0, y1 = 0 , y2= 0 , b = 0, x, y;
    for(int i = 1; i < t; ++i){
        if(x1 == -1 && cnt[i] != 4*i) x1 = i-1;
        if(cnt[i] != 0) b = i; 
    }
    if(x1 == -1) x1 = 0;

    for(x = x1 + 1; x <= t; ++x){
        if(t % x == 0){
            y = t/x; 
            
            x2 = x - x1 - 1;
            y2 = b - x2; 
            y1 = y - y2 - 1; 

            if(y1 < 0 || y2 < 0) continue;
            vector<long long> dup = cnt; 
            long long total = t; 
            bool breakcond = false; 
            for(int i = 1; i <= x; ++i){
               for(int j  =1; j <= y; ++j){
                    long long mandist = abs(i - x1 -1) + abs(j - y1 - 1);
                    if(dup[mandist] == 0){
                        breakcond = true; 
                        break; 
                    }
                    
                    --dup[mandist];
                    --total; 
               }
               if(breakcond) break; 
            }
            if(total) continue; 
            possible = true; 
            break; 
        }
    }
    if(possible){
        cout << x << " " << y << "\n" << x1 + 1 << " " << y1 + 1 << "\n";
    }
    else cout << "-1\n";
    return 0;
}