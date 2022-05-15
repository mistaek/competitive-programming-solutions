#include <cstdio>
#include <vector> 
#include <algorithm>
#include <cmath>

using namespace std; 

int main(){
    int f; 
    while(scanf("%d", &f), f){
        int r; scanf("%d", &r); 
        int i, front[f], rear[r];
        for(i = 0; i < f; i++) scanf("%d", &front[i]); 
        for(i = 0; i < r; i++) scanf("%d", &rear[i]); 
        vector<double> ratios; 
        for(i = 0; i < f; i++){
            for(int j = 0; j < r; j++) ratios.push_back((double)front[i]/rear[j]); 
        }
        sort(ratios.begin(), ratios.end()); 
        double best = 0;
        for(i = 1; i < f*r; i++){
            best = max(best, ratios[i]/ratios[i-1]);
        }
        printf("%.2f\n", best); 
    }
    return 0; 
}