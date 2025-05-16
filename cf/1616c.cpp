/*
1616C
WIP
*/

#include <cstdio>
#include <algorithm>

using namespace std;
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n); 
        int a[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        int m1 = 1, m2 = 1, c1 = 0, c2 = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                m2 = 1; c1 = 0; c2 = 0;
                for(int k = j+i; k < n; k+= i){
                    c2 = a[k] - a[k-i];
                    if(c2 == c1){
                        m2++;
                    }
                    else{
                        m1 = max(m1, m2); 
                        m2 = 2; 
                        c1 = c2;
                    }
                }
                m1 = max(m1, m2);
            }
        }
        printf("%d\n", n - m1);
    }
    return 0;
}