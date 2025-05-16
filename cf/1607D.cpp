/*
1607D
WIP
*/

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std; 
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n); 
        long long a[n]; for(int i = 0; i < n; i++){
            scanf("%lld", &a[i]); 
        }
        vector<long long> b, r; 
        for(int i = 0; i < n; i++){
            char in; scanf(" %1c", &in); 
            if(in == 'B') b.push_back(a[i]); 
            else r.push_back(a[i]); 
        }

        sort(b.begin(), b.end()); 
        sort(r.begin(), r.end());
        bool t = true; 
        int cnt = 1;
        for(int i = 0; i < b.size(); i++){
            if(b[i] < cnt) t = false; 
            cnt++;
        }
        for(int i = 0; i < r.size();i++){
            if(r[i] > cnt) t = false; 
            cnt++;
        }
        if(t) printf("yes\n"); 
        else printf("no\n");
    }    
    return 0;
}