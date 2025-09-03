/*
1174D
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 

    int n, x; cin >> n >> x; 
    vector<int> p, np; 
    for(int i = 0; i < n; ++i){
        if(x & (1 << i)) p.push_back(i); 
        else np.push_back(i); 
    }
    vector<int> seq; 
    for(auto pow : np){
        int cur = seq.size(); 
        seq.push_back((1 << pow)); 
        for(int i = 0; i < cur; ++i) seq.push_back(seq[i]); 
    }
    int unreachable = (x >= (1 << n));
    for(int i = 0; i < (int)p.size() - 1 + unreachable; ++i){
        int cur = seq.size(); 
        seq.push_back((1 << p[i])); 
        for(int i = 0; i < cur; ++i) seq.push_back(seq[i]); 
    }

    cout << seq.size() << "\n";
    for(int i = 0; i < seq.size(); ++i){
        if(i) cout << " "; 
        cout << seq[i]; 
    }
    if(seq.size()) cout << "\n"; 
    return 0;
}