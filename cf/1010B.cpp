/*
1010B
*/

#include <iostream>

using namespace std; 

int main(){
    int m, n; cin >> m >> n; 
    int seq[n]; 
    for(int i = 0; i < n; ++i){
        cout << 1 << endl; 
        cin >> seq[i];
        if(seq[i] == 0) return 0;
    }

    int lo = 1, hi = m; 
    int i = 0;
    while(lo <= hi){
        int mid = (lo+hi)/2; 
        cout << mid << endl; 
        int resp; cin >> resp; 
        resp *= seq[i % n]; 
        if(resp == 1){
            lo = mid + 1; 
        }
        else if(resp == -1) hi = mid-1;
        else return 0;
        ++i; 
    }
    return 0;
}