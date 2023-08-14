/*
1722G
cheesy sol? AC 
*/

#include <iostream>

using namespace std; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        if(n % 4 == 0){
            for(int i = 0; i < n; i++){
                cout << ((i)? " " : "") << i + 2; 
            }
        }
        else if(n%4 == 1){
            for(int i = 0; i < n - 1; i++){
                cout << ((i)? " " : "") << i + 2; 
            }
            cout << " 0"; 
        }
        else if(n % 4 == 2){
            cout << "4 1 2 12 3 8 "; 
            for(int i = 0; i < n-6; i++){
                cout << ((i)? " " : "") << i + 14; 
            }
        }
        else if(n % 4 == 3){
            for(int i = 0; i < n; i++){
                cout << ((i)? " " : "") << i + 1;  
            }
        }
        cout << "\n";
        
    }
    return 0;
}