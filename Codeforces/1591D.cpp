/*
1591A
WIP
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std; 
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        long long n, k; scanf("%lld %lld", &n, &k);
        vector<long long> pos, neg;
        long long pl = 0, nl = 0;
        for(int i = 0; i < n; i++){
            long long in; scanf("%lld", &in); 
            if(in > 0){ pl++; pos.push_back(in); }
            else {nl++; neg.push_back(-in); }
        }
        //pos.push_back(0); neg.push_back(0);
        sort(pos.begin(), pos.end());
        
        sort(neg.begin(), neg.end());
        /*
        for(int i = 0; i < pos.size(); i++){
            printf(" %d", pos[i]);
        }
        printf("\n");
        */

        long long ind1 = 0, ind2 = 0, b = 0, ans = 0;
        while(n > 0){
            if(ind1 < pl){
                b = min(ind1 + k - 1, pl - 1);
                ans += pos[b];
                n -= b - ind1 + 1;
                if(n > 0) ans += pos[b];
                ind1 += k; 
            }
            else{
                b = min(ind2 + k - 1, nl - 1); 
                ans += neg[b]; 
                n-= b - ind2 + 1;
                if(n > 0) ans += neg[b]; 
                ind2 += k;
            }
        }
        //printf("%lld\n", n);
        printf("%lld\n", ans);
    }
    return 0;
}