/*
ccc96s5
ac
*/

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std; 
int main(){
    int tc; scanf("%d", &tc); 
    while(tc--){
        int l; scanf("%d", &l); 
        vector<int> a,b; int in; 
        a.assign(l, 0); b.assign(l,0); 
        for(int i = 0; i < l; i++){ scanf("%d", &in); a[i] = -in; }
        for(int i = 0; i < l; i++){ scanf("%d", &in); b[i] = -in; }
        //needs binary search        
        int ans = 0; 
        for(int i = 0; i < l; i++){
            int val = b[i]; 

            int hi = l-1, lo = 0;
            while(hi > lo){
                int mid = (hi + lo)/2;
                if(val > a[mid]){
                    lo = mid+1; 
                }
                else{ 
                    hi = mid; 
                }
            }
            if(val >= a[lo]) ans = max(ans, i - lo);
        }
        printf("The maximum distance is %d\n", ans);

    }
    return 0;
}