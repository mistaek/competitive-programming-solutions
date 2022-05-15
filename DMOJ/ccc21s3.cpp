/*
ccc 21 s3
wip
*/

//tle... its over
#include <cstdio>
#include <algorithm>

using namespace std;
long long ans = 1e18; 
long long n, p[200001], w[200001], d[200001], mini = 1e9, minj = 0;  
long long wackoa[200001], wackob[200001];
long long origin;

void wackodown(int frnd, int position){
    long long dist = 0;
    for(int i = 0; i <= frnd; i++){
        dist += max((long long)0, abs(p[i] - position) - d[i]) * w[i]; 
    }
    if(dist < wackob[frnd]){ 
        wackoa[frnd] = position; 
        wackob[frnd] = dist; 
        wackodown(frnd, position -1);
    }
}

void wackoup(int frnd, int position){
    long long dist = 0;
    for(int i = 0; i <= frnd; i++){
        dist += max((long long)0, abs(p[i] - position) - d[i]) * w[i]; 
    }
    if(dist < wackob[frnd]){ 
        wackoa[frnd] = position; 
        wackob[frnd] = dist; 
        wackoup(frnd, position +1);
    }

}
int main(){
    scanf("%lld", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld %lld %lld", &p[i], &w[i], &d[i]);
        mini = min(mini, p[i] + d[i]); minj = max(minj, p[i] - d[i]);
    }

    wackoa[0] = p[0]; wackob[0] = 0;
    //printf("%d %d\n", wackoa[0], wackob[0]);
    for(int i = 1; i < n; i++){
        origin = wackoa[i-1];
        wackoa[i] = wackoa[i-1]; wackob[i] = wackob[i-1] + (max((long long)0, abs(p[i] - wackoa[i]) - d[i]) * w[i]); 
        wackoup(i, origin+1); 
        wackodown(i, origin-1);
        //printf("%d %d\n", wackoa[i], wackob[i]);
    }
    
    printf("%llu\n", wackob[n-1]);
    return 0;
}