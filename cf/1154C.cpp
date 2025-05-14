/*
1154C
*/

#include <iostream>
#include <algorithm>

using namespace std; 

int main(){
    long long f[3]; cin >> f[0] >> f[1] >> f[2]; 

    long long numWeeks = min(min(f[0]/3, f[1]/2), f[2]/2);

    f[0] -= 3 * numWeeks; f[1] -= 2 * numWeeks; f[2] -= 2*numWeeks; 
    //simul
    int schedule[7] = {0,1,2,0,2,1,0};
    int best = 0; 
    for(int i = 0; i < 7; ++i){
        long long orig[3];
        orig[0] = f[0], orig[1]=f[1], orig[2]=f[2]; 
        for(int j = 0; j < 7; ++j){
            if(orig[schedule[(i+j)%7]] == 0){
                best = max(best, j); 
                break; 
            }
            orig[schedule[(i+j)%7]]--;
        }
    }

    cout << 7LL * numWeeks + best << "\n";
    return 0;
}