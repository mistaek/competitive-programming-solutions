/*
2220D
*/

#include <iostream>
#include <set>
#include <algorithm>

using namespace std; 

int find_leftmost(int n) {
    int lo = 1, hi = 2*n - 1;
    while(lo < hi) {
        int m = (lo+hi+1)/2;
        int k = (2*n+1) - m + 1;
        cout << "? " << k;
        for(int i = m; i <= 2*n+1; ++i) cout << " " << i;
        cout << endl;
        int resp; cin >> resp;
        if((resp % 2) != k % 2) {
            lo = m;
        } 
        else {
            hi = m-1;
        }
    }
    return lo;
}

int find_rightmost(int n) {
    int lo = 3, hi = 2*n +1;
    while(lo < hi) {
        int m = (lo+hi)/2;
        int k = m;
        cout << "? " << k;
        for(int i = 1; i <= m; ++i) cout << " " << i;
        cout << endl;
        int resp; cin >> resp;
        if((resp % 2) != k % 2) {
            hi = m;
        } 
        else {
            lo = m+1;
        }
    }
    return lo;
}

int find_middle(int l, int r, int n) {
    int lo = l+1, hi = r-1;
    while(lo < hi) {
        int m = (lo+hi)/2;
        int k = m + (2*n+1 - r + 1);
        cout << "? " << k;
        for(int i = 1; i <= m; ++i) cout << " " << i;
        for(int i = r; i <= 2*n+1; ++i) cout << " " << i;
        cout << endl;
        int resp; cin >> resp;
        if((resp % 2) != k % 2) {
            hi = m;
        }
        else {
            lo = m+1;
        }
    }
    return lo;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int l = find_leftmost(n), r = find_rightmost(n), m = find_middle(l, r, n);
        cout << "! " << l << " " << m << " " << r;
        cout << endl;
    }
    return 0;
}