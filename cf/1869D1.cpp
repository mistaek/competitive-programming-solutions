/*
1869A
*/

#include <iostream>
#include <algorithm>
#include <map>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        long long a[n]; 
        long long sum = 0; 
        for(int i = 0; i < n; i++){
            cin >> a[i]; 
            sum += a[i]; 
        }
        if(sum % n){
            cout << "No\n";
            //cout << "avg failed\n";
            continue; 
        }   
        long long avg = sum/n; 
        int reqs[64] = {}; //64 bit for fun :)
        bool ans = true; 
        for(int i = 0; i < n; i++){
            long long diff = abs(avg - a[i]); 
            if(diff == 0) continue; 
            int state = 0; 
            for(int j = 0; j < 60; j++){
                if(diff & (1LL << j)){
                    if(state == 0){
                        state = 1; 
                        if(avg > a[i]) reqs[j]++; //send this 
                        else reqs[j]--;
                    }
                    else if(state == -1){
                        ans = false; 
                        //cout << "Failed on " << a[i] << " " << diff << "\n"; 
                        break; 
                    }
                }
                else{
                    if(state == 1){
                        state = -1; 
                        if(avg > a[i]) reqs[j]--; //rev this 
                        else reqs[j]++;
                    }
                }
            }
        }
        for(int i = 0; i < 64; i++){
            if(reqs[i] != 0){
                ans = false; 
                //cout << "Bit " << i << " not 0" << "\n";
                break; 
            }
        }
        if(ans){
            cout << "Yes\n"; 
        }
        else {
            cout << "No\n";
            //cout << "reqs failed\n";
        }
    }
    return 0;
}