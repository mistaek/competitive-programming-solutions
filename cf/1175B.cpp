/*
1175B
*/

#include <iostream>
#include <string> 
#include <vector>
#include <limits>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int l; cin >> l; 
    long long val = 0; 
    vector<long long> mtps, mtps2; 
    for(int i = 0; i < l; ++i){
        string s; cin >> s; 
        if(s == "for"){
            long long mtp; cin >> mtp; 
            mtps2.push_back(mtp); 
            if(mtp != 1){
                mtps.push_back(mtp); 
            }
        }
        else if(s == "end"){
            if( mtps2.back() != 1) mtps.pop_back();
            mtps2.pop_back();  
        }
        else {
            long long curmul = 1; 
            for(int i = mtps.size() -1; i >= 0; --i){
                curmul *= mtps[i]; 
                if(curmul > numeric_limits<unsigned int>::max()) break; 
            }
            val += curmul; 
        }
        if(val > numeric_limits<unsigned int>::max()) break; 
    }
    if(val > numeric_limits<unsigned int>::max()) cout << "OVERFLOW!!!\n";
    else cout << val << "\n"; 
    return 0;
}