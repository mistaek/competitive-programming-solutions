/*
992D
AC :)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>


using namespace std; 

void test(){
    while(true){
        int n, k; 
        n = rand() % 25;
        k = rand() % 10;
        ++k;
        vector<long long> a, fwd, back; 

        vector<long long> randarr; 
        int ctr = 0;
        long long ans = 0, total = 0;
        for(int i = 0; i < n; ++i){
            int num = 0; 
            while(num == 0)num = rand() % 25;
            
            if(rand() % 3 == 0)  num = 1; 
            randarr.push_back(num);
            if(num == 1){
                ++ctr; ++total; 
                if(k == 1) ++ans; 
            }
            else{
                total += num;
                a.push_back(num);  
                back.push_back(ctr);
                ctr = 0;
            }
        }

        for(int i = 0; i < (int) a.size()-1; ++i){
            fwd.push_back(back[i+1]);
        }
        fwd.push_back(ctr);
    
    

        long long s = 0, p = 1; //sum, product 
        for(int i = 0; i < (int)a.size(); ++i){
        s = 0, p = 1; 
        for(int j = i; j < (int)a.size(); ++j){
            s += a[j];
            if(j != i) s += back[j];
            if(numeric_limits<long long>::max() /a[j] > p) p *= a[j]; 
            else p = numeric_limits<long long>::max();
            if(p > k *total) break; // log 1e13 ~= 43
            if(p % k) continue;
            long long reqOnes = p/k - s; //need s to be p/k
            if(reqOnes <0) continue; 

            //have access to fwd[i] + back[i] ones, but can only stretch reqOnes in one direction
            long long totalOnes = min(reqOnes, fwd[j]) + min(reqOnes, back[i]);
            if(totalOnes >= reqOnes){
                ans += totalOnes - reqOnes + 1; 
            }
            if(i == 0 && j == 1){
                //cout << p << " " << s << " " << reqOnes << "\n";
            }
        }
        }

        long long bruteans = 0;
        vector<pair<int, int>> intvs; 
        for(int i = 0; i < n; ++i){
            s = 0, p = 1; 
            for(int j = i; j < n; ++j){
                p *= randarr[j]; 
                s += randarr[j]; 
                if(p > k * total) break; 
                if(p % k == 0 && p/k == s){
                    intvs.push_back({i, j});
                    bruteans++;
                }
            }
        }
        if(bruteans != ans){
            cout << n << " " << k << "\n";
            /*for(int i = 0; i < n; ++i){
                cout << randarr[i] << " "; 
            }*/
            for(auto pairs : intvs){
                cout << pairs.first << " " << pairs.second << "\n";
            }
            cout << "\n";
            cout << bruteans << " " << ans << "\n";
            break; 
        }
        
    }
}
int main(){
    /*testing
    srand(time(0));
    test(); 
    return 0;
    //*/
    int n, k; cin >> n >> k; 
    vector<long long> a, fwd, back; 

    int ctr = 0;
    long long ans = 0, total = 0;
    for(int i = 0; i < n; ++i){
        int num; cin >> num; 
        if(num == 1){
            ++ctr; ++total; 
            if(k == 1) ++ans; 
        }
        else{
            total += num;
            a.push_back(num);  
            back.push_back(ctr);
            ctr = 0;
        }
    }

    for(int i = 0; i < (int) a.size()-1; ++i){
        fwd.push_back(back[i+1]);
    }
    fwd.push_back(ctr);
    
    

    long long s = 0, p = 1; //sum, product 
    for(int i = 0; i < (int)a.size(); ++i){
        s = 0, p = 1; 
        for(int j = i; j < (int)a.size(); ++j){
            s += a[j];
            if(j != i) s += back[j];
            if(numeric_limits<long long>::max() /a[j] > p) p *= a[j]; 
            else p = numeric_limits<long long>::max();
            if(p > k *total) break; // log 1e13 ~= 43
            if(p % k) continue;
            long long reqOnes = p/k - s; //need s to be p/k
            if(reqOnes <0) continue; 

            //have access to fwd[i] + back[i] ones, but can only stretch reqOnes in one direction
            long long totalOnes = min(reqOnes, fwd[j]) + min(reqOnes, back[i]);
            if(totalOnes >= reqOnes){
                ans += totalOnes - reqOnes + 1; 
            }
            if(i == 0 && j == 1){
                //cout << p << " " << s << " " << reqOnes << "\n";
            }
        }
    } 

    cout << ans << "\n";
    return 0;
}