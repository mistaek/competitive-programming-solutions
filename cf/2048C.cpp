/*
2048C
*/

#include <iostream>
#include <string>
using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        string str; cin >> str; 
        
        int n = str.length();
        int s[n]; 
        int bestl = 0, bestr = 0;

        for(int i = 0; i < n; ++i){
            s[i] = str[i] - '0';
            if(s[i] == 0) bestl = i, bestr = i;
        }

        
        for(int i = 0; i < n; ++i){ //end at index i
            bool suffixbetter = false;
            for(int j = i; j >= 0; --j){
                int curxor = s[j]^s[n-(i-j)-1], bestxor = 0;
                if(i - j <= bestr - bestl){
                    bestxor = s[bestr - (i-j)]^s[n-1 - (i-j)];
                }
                if(curxor > bestxor) suffixbetter = true; 
                else if(curxor < bestxor) suffixbetter = false; 
                if(curxor == 1){
                    if(i - j + 1 == bestr - bestl + 1){ //length is equivalent
                        if(suffixbetter){
                            bestl = j, bestr = i; 
                            suffixbetter = false; 
                        }
                    }
                    else if(i-j + 1 > bestr - bestl + 1){
                        //ALWAYS BETTER (longer length)
                        bestl = j, bestr= i; suffixbetter = false; 
                    }
                }
                
            }
        }

        cout << 1 << " " << n << " " << bestl + 1 << " " << bestr + 1 << "\n"; 
    }
    return 0;
}