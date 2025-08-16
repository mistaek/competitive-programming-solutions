/*
2128B
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int tc; cin >> tc; 
    while(tc--){
        int n; cin >> n; 
        vector<int> p(n); 
        for(int i = 0; i < n; ++i){
            cin >> p[i]; 
        }
        int i = 0, j = n-1; 
        int turn = 0; //take min when even, max when odd 
        string out; 
        while(i <= j){
            if(p[i] <= p[j]){
                if(turn == 0){
                    out.push_back('L'); 
                    ++i; 
                }
                else{
                    out.push_back('R'); 
                    --j; 
                }
            }
            else{
                if(turn == 0){
                    out.push_back('R'); 
                    --j; 
                }
                else{
                    out.push_back('L'); 
                    ++i; 
                }
            }

            turn = 1-turn; 
        }
        cout << out << "\n"; 
    }
    return 0;
}