/*
MHC2023 P1
*/

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std; 

int main(){
    int T; cin >> T;
    for(int t = 1; t <= T; t++){
        int n; cin >> n; 
        long long a[n]; 
        for(int i = 0; i < n; i++){
            cin >> a[i]; 
        }

        sort(a, a+n); 
        //cout << "\n";
        
        double dist; 
        if(n == 5){
            double ms1 = (a[0] + a[2])/2.0, me1 = (a[n-1] + a[n-2])/2.0; 
            double ms2 = (a[0] + a[1])/2.0, me2 = (a[n-1] + a[n-3])/2.0;
            double dist1 = me1 - ms1, dist2 = me2 - ms2; 
            //cout << dist1 << " " << dist2 << "\n"; 
            dist = max(dist1, dist2);
        }
        else{
            long long ms = a[0] + a[1], me = a[n-1] + a[n-2]; 
            dist = (me - ms)/2.0;
        }


        cout <<"Case #" << t << ": "<< std::setprecision (15) << dist << "\n";
        
    }
    return 0;
}