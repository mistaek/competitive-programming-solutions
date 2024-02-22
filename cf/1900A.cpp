/*
1900A
*/

#include <iostream>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int cnt = 0, total = 0, mcnt = 0; 
        for(int i = 0; i < n; i++){
            char c; cin >> c;
            if(c == '.'){
                ++cnt; 
                if(cnt == 3) mcnt = 1; 
                ++total; 
            }
            else{
                cnt = 0;
            }
        }

        cout << (mcnt ? 2 : total) << "\n";
    }
    return 0;
}