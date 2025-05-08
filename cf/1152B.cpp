/*
1152A
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    int x; 
    vector<int> ans; 
    cin >> x; 
    int mag = 0; //find magnitude of cur number
    for(int i = 0; i <= 20; ++i){
        if((1 << i) > x){
            mag = i; 
            break; 
        }
    }
    int ops = 0; 
    while(x != (1<<mag) - 1){
        for(int i = mag-1; i >= 0; --i){
            if((x & (1 << i)) == 0){
                ++ops; 
                ans.push_back(i+1);
                x^= (1 <<(i+1)) - 1; 
                break; 
            }
        }
        if(x == (1 << mag) - 1) break; 
        else{
            ++ops; 
            x = x + 1; 
        }
    }

    cout << ops << "\n"; 
    for(int ni : ans){
        cout << ni << " "; 
    }
    if(ans.size()) cout << "\n";

    return 0; 
}