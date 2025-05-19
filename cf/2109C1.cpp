/*
2109A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set> 
#include <map> 
#include <functional>

using namespace std; 

int main(){
    
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; int resp; 
        cout << "digit" << endl; 
        cin >> resp; 
        cout << "digit" << endl; 
        cin >> resp; 

        int cut = 8; 
        int ctr = 4; 
        while(ctr--){
            cout << "add " << -cut << endl; 
            cut /= 2; 
            cin >> resp; 
        }

        if(n == 1){
            cout << "!" << endl; 
            cin >> resp; 
        }
        else{
            cout <<"add " << n-1 << endl; 
            cin >> resp; 
            cout << "!" << endl; 
            cin >> resp; 
        }
    }
    return 0;
}