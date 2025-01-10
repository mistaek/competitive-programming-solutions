/*
2057D
*/

#include <iostream>
#include <vector>

using namespace std; 
vector<int> a;
vector<long long> stmaxright, stmaxleft;
vector<pair<long long, long long>> stplusi, stminusi;

void buildplusminus(int i, int l, int r){
    if(l == r){
        stplusi[i] = {a[l] + l, a[l] + l};
        stminusi[i] = {a[l] - l, a[l] - l};
    }
    else{
        int mid = (l+r)/2; 
        buildplusminus(i+1, l, mid); 
        buildplusminus(i+2*(mid - l + 1), mid+1, r);
        stplusi[i] = {max(stplusi[i+1].first, stplusi[i + 2*(mid - l + 1)].first), min(stplusi[i+1].second, stplusi[i + 2*(mid - l + 1)].second)}; 
        stminusi[i] = {max(stminusi[i+1].first, stminusi[i + 2*(mid - l + 1)].first), min(stminusi[i+1].second, stminusi[i + 2*(mid - l + 1)].second)}; 
    }
}

// p has been updated to x
void updplusminus(int i, int l, int r, int p, int x){
    if(p < l || p > r) return;
    if(l == p && r == p){
        stplusi[i] = {x + l, x+l}; 
        stminusi[i] = {x-l, x-l};
    }
    else{
        int mid = (l+r)/2; 
        updplusminus(i+1, l, mid, p, x); 
        updplusminus(i+2*(mid - l + 1), mid+1, r, p, x);
        stplusi[i] = {max(stplusi[i+1].first, stplusi[i + 2*(mid - l + 1)].first), min(stplusi[i+1].second, stplusi[i + 2*(mid - l + 1)].second)}; 
        stminusi[i] = {max(stminusi[i+1].first, stminusi[i + 2*(mid - l + 1)].first), min(stminusi[i+1].second, stminusi[i + 2*(mid - l + 1)].second)}; 
    }
}


void buildrightleft(int i, int l, int r){
    if(l == r){
        stmaxright[i] = 0; 
        stmaxleft[i] = 0;
    }
    else{
        int mid = (l+r)/2; 
        buildrightleft(i+1, l, mid); 
        buildrightleft(i+2*(mid - l + 1), mid+1, r);
        stmaxright[i] = max(max(stmaxright[i+1], stmaxright[i+2*(mid - l + 1)]), stminusi[i + 2*(mid - l + 1)].first - stminusi[i + 1].second);
        stmaxleft[i] = max(max(stmaxleft[i+1], stmaxleft[i+2*(mid-l+1)]), stplusi[i+1].first - stplusi[i+2*(mid-l+1)].second );
    }
}
void updrightleft(int i , int l, int r, int p){
    if(p < l || p > r) return ;
    if(l == p && r == p){
        stmaxright[i] = 0; 
        stmaxleft[i] = 0; // no diff here
    }
    else{
        int mid = (l+r)/2; 
        updrightleft(i+1, l, mid, p); 
        updrightleft(i+2*(mid - l + 1), mid+1, r, p);
        stmaxright[i] = max(max(stmaxright[i+1], stmaxright[i+2*(mid - l + 1)]), stminusi[i + 2*(mid - l + 1)].first - stminusi[i + 1].second);
        stmaxleft[i] = max(max(stmaxleft[i+1], stmaxleft[i+2*(mid-l+1)]), stplusi[i+1].first - stplusi[i+2*(mid-l+1)].second );
    }
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int tc; cin >> tc; 
    while(tc--){
        int n, q; cin >> n >> q; 
        a = vector<int>(n); 
        stmaxright = stmaxleft = vector<long long>(2*n);
        stplusi = stminusi = vector<pair<long long, long long>>(2*n); 

        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        buildplusminus(0, 0, n-1);
        buildrightleft(0, 0, n-1);
        cout << max(stmaxright[0], stmaxleft[0]) << "\n";
        for(int i = 0; i < q; ++i){
            int p, x; cin >> p >> x;
            --p;
            updplusminus(0, 0, n-1, p, x);
            updrightleft(0, 0, n-1, p);
            cout << max(stmaxright[0], stmaxleft[0]) << "\n";

        }
    }
    return 0;
}