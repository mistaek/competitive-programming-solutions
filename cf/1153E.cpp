/*
1153E
AC, missed an observation
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(){
    int n; cin >> n; 

    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    for(int i = 1; i <= n; ++i){
        cout << "? " << i << " 1 " << i << " " << n << endl; 
        int ans; cin >> ans; 
        if(ans % 2){
            if(x1 == 0) x1 = i; 
            else x2 = i; 
        }
    }

    if(x1 == 0){
        //scan for y insteads
        for(int i = 1; i <= n; ++i){
            cout << "? 1 " << i << " " << n << " " << i << endl; 
            int ans; cin >> ans; 
            if(ans % 2){
                if(y1 == 0) y1 = i; 
                else y2 = i; 
            }
        }

        int lo = 1; int hi = n; 
        while(lo < hi){
            int mid = (lo + hi)/2; 
            cout << "? " << "1 " << y1 << " " << mid << " " << y1 << endl; 
            int ans; cin >> ans; 
            if(ans % 2){
                hi = mid; 
            }
            else{
                lo = mid+1; 
            }
        }

        x1 = x2 = lo; 
        cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl; 

    }
    else{
        //binary search both y1 and y2
        int lo = 1; int hi = n; 
        while(lo < hi){
            int mid = (lo+hi)/2; 
            cout << "? " << x1 << " 1 " << x1 << " " << mid << endl; 
            int ans; cin >> ans; 
            if(ans % 2){
                hi = mid; 
            }
            else{
                lo = mid+1; 
            }
        }

        y1 = lo; 

        lo = 1, hi = n; 

        while(lo < hi){
            int mid = (lo+hi)/2; 
            cout << "? " << x2 << " 1 " << x2 << " " << mid << endl; 
            int ans; cin >> ans; 
            if(ans % 2){
                hi = mid; 
            }
            else{
                lo = mid+1; 
            }
        }

        y2 = lo; 
        cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl; 
    }
    

    return 0;
}