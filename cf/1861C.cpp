/*
1861C
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std; 

int main(){
    cin.tie(0); 
    ios::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        string s; cin >> s; 
        bool ans = true; 
        int curl = 0, knownSorted = 0, maxSorted = 0, sorted = 1;
        //1 is sorted, 0 is unknown, -1 is unsorted 
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '+'){
                curl++;
                if(sorted != -1 && curl > 1){
                    maxSorted = curl; 
                    sorted = 0; 
                }
                else if(sorted == 1){
                    maxSorted = knownSorted = curl; 
                }
            }
            else if(s[i] == '-'){
                curl--;
                if(curl <= knownSorted){
                    knownSorted = maxSorted = curl; 
                    sorted = 1;
                }
                else if(curl <= maxSorted){
                    maxSorted = curl; 
                    sorted = 0;
                }
            }
            else if(s[i] == '0'){
                if(curl <= 1 || sorted == 1){
                    ans = false; 
                    break; 
                }
                else if(maxSorted >= curl){
                    maxSorted = curl-1; 
                    sorted = -1; 
                }
            }
            else if(s[i] == '1'){
                if(sorted == -1){
                    ans = false; 
                    break; 
                }
                else{
                    maxSorted = knownSorted = curl; 
                    sorted = 1; 
                }
            }
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}