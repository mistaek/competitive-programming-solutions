/*
2205
*/

#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 

vector<int> nums; 
int state = 0;
void all(int n){
    if(n == 1){
        nums.push_back(state); 
        state ^= 1; 
        nums.push_back(state); 
    }
    else{
        all(n-1); 
        state ^= (1 << (n-1));
        all(n-1); 
    }
}

int main(){
    int n; cin >> n; 
    all(n);
    for(int num : nums){
        for(int j = 0; j < n; ++j){
            cout << ((num >> j) & 1); 
        }
        cout << "\n";
    }
    return 0;
}