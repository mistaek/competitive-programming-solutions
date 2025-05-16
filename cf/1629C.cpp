/*
1629A
WIP
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n);
        vector<int> occ[n+1];
        int ind[n+1] = {};
        for(int i = 0; i < n; i++){
            int a;scanf("%d", &a); 
            occ[a].push_back(i);
        }
        vector<int> b; 
        int id =0, mex = 0, oldid = 0;
        while(id < n){
        for(mex = 0; mex <= n; mex++){
            //printf("considering mex %d\n", mex); 
            if(id >= n) break;
            int i;
            for(i = ind[mex]; i < occ[mex].size(); i++){
                if(oldid > occ[mex][i]) continue;
                else{
                    //printf("occurence of %d found at %d\n", mex, occ[mex][i]);
                    id = max(id, occ[mex][i]);
                    ind[mex] = i+1;
                    break; 
                }
            }
            if(i == occ[mex].size()){
                b.push_back(mex);
                id++;
                oldid = id;
                break;
            }
        }
        }
        printf("%d\n", b.size());
        for(int i = 0; i < b.size(); i++){
            if(i) printf(" %d", b[i]); 
            else printf("%d", b[i]); 
        }
        printf("\n");

    }
    return 0;
}