/*
ecoo20p2
ray
AC
*/

#include <cstdio>
#include <map>
#include <string> 
#include <iostream>
#include <queue>

using namespace std; 



int main(){
    int TC; scanf("%d\n", &TC);
    while(TC--){
        map<string, priority_queue<int>> catalog; 
        int n; scanf("%d\n", &n); 
        for(int i = 0; i < n; i++){
            int m; scanf("%d", &m); 
            for(int j = 0; j < m; j++){
                string name; cin >> name; 
                int p, q; scanf(" %d %d", &p, &q);
                for(int k = 0; k < q; k++){
                    catalog[name].push(-p);
                }
            }
        }

        int k; scanf("%d", &k); int ans = 0; 
        for(int i = 0; i < k; i++){
            string name; cin >> name; 
            int q; scanf(" %d", &q);
            while(q--){
                ans+= -catalog[name].top(); 
                catalog[name].pop();
            }
        }

        printf("%d\n", ans);

    }
    return 0;
}