/*
MHC2023R1B.cpp
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    int T; cin >> T; 
    for(int t= 1; t <= T; t++){
        long long p; cin >> p; 
        vector<int> out; 
        int sum = 0; 
        for(long long i = 2; i * i <= p; i++){
            while(p % i == 0){
                out.push_back(i); 
                sum += i; 
                p/= i; 
            }
        }
        if(p > 1){ out.push_back(p);sum += p;}

        cout << "Case #" << t << ": ";
        if(sum > 41){
            cout << -1; 
        }
        else {
            while(sum < 41){
                out.push_back(1);
                sum++; 
            }
            if(out.size() > 100){
                cout << -1; //should never happen
            }
            else{
                cout << out.size(); 
                for(int i = 0; i < out.size(); i++){
                    cout << " " << out[i];
                }
            }
        }
        cout << "\n";

    }
    return 0;
}