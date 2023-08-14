/*
1841C
*/

#include <iostream>
#include <string>
#include <vector> 
#include <map>
#include <algorithm>
using namespace std; 
map<char, long long> val; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    val['A'] = 1; val['B'] = 10; val['C'] = 100; val['D'] =1000; val['E'] = 10000;
    int t; cin >> t; 
    while(t--){
        string s; cin >> s; 
        if(s.length() == 1){
            cout << 10000 << "\n";
            continue; 
        }
        vector<long long> lm, v(s.length()); 
        long long first[5] = {},last[5] = {}; 
        for(int i = 0; i < 5; i++){
            first[i] = -1; 
        }
        for(int i = 0; i < s.length(); i++){
            if(first[s[i] - 'A'] == -1){
                first[s[i] - 'A'] = i; 
            }
            last[s[i] - 'A'] = i; 
        }
        
        int ans = 0;
        int mv = 0, nans = 0;  
        for(int i =s.length() -1; i >= 0; i--){
            if(s[i] - 'A' > mv){
                mv = s[i] - 'A'; 
            }
            if(s[i] - 'A' < mv){
                ans -= val[s[i]]; 
            }
            else{
                ans += val[s[i]]; 
            }
        }
        for(int j = 0; j < 5; j++){
            if(first[j] == -1) continue; 
            for(int c = 0; c < 5; c++){
                char nc = 'A' + c; 
                swap(s[first[j]], nc); 
                mv = 0, nans = 0;  
                for(int i =s.length() -1; i >= 0; i--){
                    if(s[i] - 'A' > mv){
                        mv = s[i] - 'A'; 
                    }
                    if(s[i] - 'A' < mv){
                        nans -= val[s[i]]; 
                    }
                    else{
                        nans += val[s[i]]; 
                    }
                }
                ans = max(ans, nans); 
                swap(s[first[j]], nc); 
                swap(s[last[j]], nc); 
                mv = 0, nans = 0;  
                for(int i =s.length() -1; i >= 0; i--){
                    if(s[i] - 'A' > mv){
                        mv = s[i] - 'A'; 
                    }
                    if(s[i] - 'A' < mv){
                        nans -= val[s[i]]; 
                    }
                    else{
                        nans += val[s[i]]; 
                    }
                }
                ans = max(ans, nans); 
                swap(s[last[j]], nc); 
            }
        }
        cout << ans << "\n";
    }
    return 0;
}