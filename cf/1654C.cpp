/*
1654C
WIP
*/

#include <cstdio>
#include <map>

using namespace std; 

map<long long, int> allowed; 

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        allowed.clear();
        int n; scanf("%d", &n); 
        long long arr[n], sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%lld", &arr[i]); 
            sum+= arr[i];
        }

        allowed[sum] = 1;
        long long pow = 2;
        while(true){
            if((sum % pow)){
                if(allowed.count((sum/pow)) == 0) allowed[(sum/pow)] = 0;
                if(allowed.count((sum/pow) + 1) == 0) allowed[(sum/pow) + 1] = 0;
                allowed[(sum/pow) +1] += allowed[(sum/(pow/2))];
                allowed[(sum/pow)] += allowed[(sum/(pow/2))];
            }
            else{
                if(allowed.count((sum/pow)) == 0) allowed[(sum/pow)] = 0;
                allowed[(sum/pow)] += allowed[(sum/(pow/2))];
            }
            if(sum/pow == 0) break;
            pow*=2; 

        }
        bool ans = true; 
        for(int i =0 ; i < n; i++){
            if(allowed.count(arr[i]) == 0) ans = false; 
            else{
                allowed[arr[i]--];
                if(allowed[arr[i]] < 0) ans = false;
            }
        }
        if(ans) printf("YES\n"); 
        else printf("NO\n");
    }
    return 0;
}