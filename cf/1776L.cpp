/*
1776L
AC
*/

#include <iostream>
#include <string>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n; 
    string s; cin >> s; 
    long long add = 0, sub = 0;
    for(int i =0; i < n; i++){
        if(s[i] == '+') add++; 
        else sub++;
    }
    int q; cin >> q; 
    while(q--){
        long long a, b; cin >> a >> b; 
        if(a > b) swap(a, b);
        if(add > sub) swap(add, sub);
        long long goal = a*add;
        long long lo = 0, hi = sub; 
        bool ans = false; 
        while(lo <= hi){
            long long mid = (lo + hi)/2;
            long long res =(mid * a) + ((sub - mid)*b);
            if(res == goal){
                ans = true; break; 
            }
            if((mid * a) + ((sub - mid)*b) < goal){
                hi = mid-1; 
                continue; 
            }
            else {
                lo = mid+1; 
            }
        }
        if(ans == true){
            cout << "YES\n"; 
            continue; 
        }
        goal = b * add; 
        lo = 0, hi = sub; 
        while(lo <= hi){
            long long mid = (lo + hi)/2;
            long long res =(mid * a) + ((sub - mid)*b);
            if(res == goal){
                ans = true; break; 
            }
            if((mid * a) + ((sub - mid)*b) < goal){
                hi = mid-1; 
                continue; 
            }
            else {
                lo = mid+1; 
            }
        }
        if(ans == true){
            cout << "YES\n"; 
            continue; 
        }
        cout << "NO\n";
        //some unnecessary code dupe but idc
    }
    return 0;
}