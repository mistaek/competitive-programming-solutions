/*
bbc09d for dev
ray
wip
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std; 

vector<long long> tasks;

int main(){
    //input;
    int n; scanf(" %d", &n); 

    for(int i = 0; i < n; i++){
        long long in; scanf("%lld", &in); 
        tasks.push_back(in);
    }
    //processing and output
    long long ans = 0; 
    sort(tasks.begin(), tasks.end());
    for(int i = n-1; i >= 0; i--){
        ans += (tasks[i]*tasks[n -(i+1)]);
    }
    printf("%lld\n", ans%10007);
    return 0; 
}