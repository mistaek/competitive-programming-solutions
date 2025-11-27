/*
1178E
*/
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    string s; 
    cin >> s; 
    int i = 0, j = s.length() -1; 
    vector<char> out(s.length()); 
    while (i<=j){
        if(s[i] == s[j]){
            // take this pair always
            out[i] = out[j] = s[j];
            ++i; 
            --j;
        }
        else if(s[i] == s[j-1]){
            out[i] = out[j-1] = s[j-1];
            ++i; j-=2; 
        }
        else if(s[i+1] == s[j]){
            out[i+1] = out[j] = s[j];
            i +=2; --j;
        }
        else if (s[i+1] == s[j-1]){
            out[i+1] = out[j-1] = s[j-1]; 
            i+=2; j -=2; 
        }
    }

    for(size_t i = 0; i < s.length(); ++i){
        if (out[i]) cout << out[i]; 
    }
    cout << "\n";
    return 0;
}