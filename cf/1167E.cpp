/*
1167E
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);  
    cin.tie(0); 

    int n, x; cin >> n >> x;
    vector<int> a(n);
    vector<int> prefMax(n), sufMin(n);  
    for(int i = 0; i < n; ++i){
        cin >> a[i]; 
        prefMax[i] = a[i]; 
        if(i) prefMax[i] = max(prefMax[i], prefMax[i-1]); 
    }
    for(int i = n-1; i >= 0; --i){
        sufMin[i] = a[i]; 
        if(i < n-1) sufMin[i] = min(sufMin[i], sufMin[i+1]); 
    }

    vector<int> lBound(x+2, x), rBound(x+2, 1); 
    // l must be <= lBound[i] if r < i 
    // r must be >= rBound[i] if l > i
    
    for(int i = 0; i < n; ++i){
        if(a[i] > sufMin[i]) lBound[a[i]] = sufMin[i];
        if(a[i] < prefMax[i]) rBound[a[i]] = prefMax[i]; 
    }
    vector<int> jumpL(x+2, x), jumpR(x+2, 1); 
    //jumpR[i] = largest r > i which conflicts with something larger than r
    //jumpL[i] = smallest l < i which conflicts with something smaller than l
    for(int i = x-1; i >= 1; --i){
        if(rBound[i] > i) jumpR[i] = i; 
        jumpR[i] = max(jumpR[i], jumpR[i+1]); 
    }
    for(int i = 2; i <= x; ++i){
        if(lBound[i] < i) jumpL[i] = i; 
        jumpL[i] = min(jumpL[i], jumpL[i-1]); 
    }
    for(int i = x-1; i >= 1; --i){
        lBound[i] = max(lBound[i], lBound[i+1]); 
    }
    for(int i = 2; i <= x; ++i){
        rBound[i] = max(rBound[i], rBound[i-1]); 
    }

    // try every l
    long long ans = 0; 
    for(int i = 1; i <= x; ++i){
        int L = i, R = i; 
        if(jumpL[i] < L) continue; 
        R = max(R, max(rBound[i-1], jumpR[i])); 
        L = min(L, lBound[R+1]); // since i + 1 isn't included, decrease
        
        if(L == i){
            //cout << "OK: " << L << " " << R << "\n"; 
            ans += x - R+1; 
        }
    }
    cout << ans << "\n";
    return 0; 
}