/*
925C
AC :)
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    int n; cin >> n; 
    vector<vector<long long>> buckets(64);
    vector<int> bucket_indices(64, 0);
    for(int i = 0; i < n; ++i){
        long long b; cin >> b; 
        for(int j = 60; j >= 0; --j){
            if(b & (1LL << j)){
                buckets[j].push_back(b);
                break; 
            }
        }
    }

    long long cur_xor = 0; 
    vector<long long> out; 
    for(int i = 0; i < n; ++i){
        bool added = false;
        for(int j = 0; j < 64; ++j){
            if((cur_xor & (1LL << j)) == 0 && bucket_indices[j] < (int)buckets[j].size()){
                out.push_back(buckets[j][bucket_indices[j]]);
                cur_xor ^= buckets[j][bucket_indices[j]]; 
                ++bucket_indices[j];
                added = true;
                break; 
            }
        }
        if(!added) break;
    }

    if((int)out.size() == n){
        cout << "Yes\n"; 
        for(int i =0; i < n; ++i){
            if(i) cout << " ";
            cout << out[i];
        }
        cout << "\n";
    }
    else cout << "No\n";
    
    return 0;
}