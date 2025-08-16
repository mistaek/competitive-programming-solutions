/*
1166B
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int k; cin >> k; 
    int n = 0, m = 0; 
    for(int i = 1; i * i <= k; ++i){
        if(k % i == 0){
            n = i, m = k / i; 
            if(m >= 5 && n >= 5) break; 
        }
    }
    if(n < 5 || m < 5){
        cout << "-1\n"; 
        return 0;
    }

    vector<vector<char>> out(n, vector<char>(m, 'a')); 

    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << vowels[(j + i) % 5];
        }
        //cout << "\n"; 

    }
    cout << "\n"; 
    
    return 0; 
}