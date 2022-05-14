/*
2022A1P2 
WIP
*/

#include <iostream>

using namespace std; 

int main(){
    int tc; cin>> tc; 
    while(tc--){
        int n; cin >> n; int cpy = n;  // 100
        long long sum = 0;
        for(int i = 1; i <= 536870912; i*=2){
            if(i >= 2) cout << " " << i; 
            else cout << i;
            sum += i;
            n--;
            if(n <= 0) break; //shouldn't happen
        }
        cout << " " << 3; 
        n--;
        while(n > 0){
            if(n <= 0) break; 
            int i = 536870910, j = 536870914; 
            cout << " " << i; 
            sum += i;
            i-= 2; 
            n--; 
            if(n <= 0) break; 
            cout << " " << j; 
            j+= 2; 
            sum += j;
            n--; 
        }
        cout << endl;
        int  nxt; 
        for(int i = 0; i < cpy; i++){
            cin >> nxt; 
            sum += nxt; 
        }

        long long obj = sum/2, pow = 1;
        while(obj){
            if(obj < sum/2) cout << " ";
            if((obj & 1) && pow <= 536870912 ){
                cout << pow; 
            }
            else if( (obj & 1)){
                long long diff = 2, copyy = pow; 
                while(copyy){
                    cout << 536870912 + diff << " " << 536870912 -diff;
                    copyy -=  1073741824; 
                    diff += 2;
                }
            }
            obj/= 2; 
        }
        cout << endl;



         
    } 
    return 0;
}