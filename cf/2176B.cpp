/*
2176B
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int bigblock = 0, curblock = 0;
        string s; cin >> s;
        int start = 0;
        for (int i = 0; i < n; ++i){
            if(s[i] == '1') {
                start = i; break;
            }
        }
        for(int i = 0; i < n + 1; ++i) {
            if(s[(i+start)%n] == '1') {
                bigblock = max(curblock, bigblock); 
                curblock = 0;
            }
            else ++curblock;
        }

        cout << bigblock << "\n";
    }
    return 0;
}