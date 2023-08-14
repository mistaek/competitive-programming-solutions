/*
1801A
WIP
*/

#include <iostream>

using namespace std; 
int main(){
    int m[20][20];
    int cnter = 0;
    for(int i = 0; i < 200; i += 2){
        for(int j = 0; j < 200; j+=2){
            m[i][j] = 4*cnter + 0;
            m[i][j+1] = 4*cnter + 1; 
            m[i+1][j] = 4*cnter + 2; 
            m[i+1][j+1] = 4*cnter + 3; 
            cnter++;
        }
    }

    int t; cin >> t; 
    while(t--){
        int a, b; cin >> a >> b; 
        cout << a * b;
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                cout << m[i][j] << "\n"; 
            }
        }
    }
    return 0;
}