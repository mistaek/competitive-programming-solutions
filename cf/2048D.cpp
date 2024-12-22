/*
2048D
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

/*void test(){
    srand(time(0));
    while(true){
    int n = (rand() % 7) +1, m = (rand() % 7)  + 1;
    vector<long long> a(n), b(m), ans; 
    for(int i = 0; i < n; ++i){
        a[i] = rand() % 50;
    } 
    for(int i = 0; i < m; ++i){
        b[i] = rand() % 60;
    }
    long long kevin = a[0]; 
    sort(a.begin(), a.end()); 
    sort(b.begin(), b.end());

    auto it = upper_bound(b.begin(), b.end(), kevin);
    reverse(it, b.end());

    for(int k = 1; k <= m; ++k){
        int sum =0;
        for(int i = k-1; i < m; i += k){
            if(b[i] <= kevin) ++sum; 
            else{
                sum += 1 + (a.end() - lower_bound(a.begin(), a.end(), b[i]));
            }
        }
        ans.push_back(sum);
    }
    sort(b.begin(), b.end());
    for(int k = 1; k <= m; ++k){
        do{
            int sum =0;
            for(int i = 0; i < m/k; ++i){
                long long best = 1e9;
                for(int j = i * k; j < (i+1)*k; ++j){
                    if(b[j] > kevin){
                        best = min(best, b[j]);
                    }
                }
                sum += 1 + (a.end() - lower_bound(a.begin(), a.end(), best));
            }
            if(sum < ans[k-1]){
                cout << n << " " << m << " " << kevin <<"\n"; 
                for(int i = 0; i < n; ++i){
                    cout << a[i] << " "; 
                }
                cout << "\n";
                for(int i = 0; i < m; ++i){
                    cout << b[i] << " ";
                }
                cout << "\n";
                cout << k << " " << sum << " " << ans[k-1] << "\n"; 
                return; 
            }
        }while(next_permutation(b.begin(), b.end()));
    }
    }
}*/
int main(){
    //test(); 
    //return 0;
    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m; 
        vector<long long> a(n), b(m);
        long long kevin = 0;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        for(int i = 0; i < m; ++i){
            cin >> b[i];
        }
        kevin = a[0]; 
        sort(a.begin(), a.end()); 
        sort(b.begin(), b.end());

        auto it = upper_bound(b.begin(), b.end(), kevin);
        reverse(it, b.end());

        for(int k = 1; k <= m; ++k){
            long long sum =0;
            for(int i = k-1; i < m; i += k){
                if(b[i] <= kevin) ++sum; 
                else{
                    sum += 1LL +  (long long)(a.end() - lower_bound(a.begin(), a.end(), b[i]));
                }
            }
            if(k > 1) cout << " "; 
            cout << sum;
        }
        cout << "\n";
    }
    return 0;
}