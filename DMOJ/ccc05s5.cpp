/*
ccc05p5
ac
*/

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int n, tree[1000010], frnk[1000010];
long long ans;
vector<pair<int, int>> scores; 

//found a fenwick ver, gonna try to understand it 
void add(int idx){
    while(idx <= n){ // 1indexed
        tree[idx]++;
        idx += (idx & -idx); 
    }
}

int freq(int idx){
    int ret = 0; 
    while(idx > 0){
        ret += tree[idx]; 
        idx-= (idx & -idx);
    }
    return ret;
}
int main(){
    scanf("%d", &n);scores.assign(n, {0,0});
    for(int i = 0; i < n; i++){
        scanf("%d", &scores[i].first); scores[i].second = i;
    }
    sort(scores.begin(), scores.end());
    for(int i = 0; i < n; i++) frnk[scores[i].second] = n-i;
    for(int i = 0; i < n; i++){
        add(frnk[i]); ans += freq(frnk[i]);
    }
    printf("%.2lf\n", (double)ans/n);
    return 0;    
}




















































/*
//merge sort method, kinda copied tbh, 
//seems too slow, how in the world 

int a[100005];
int n;
long long ans = 0; 

void merge(int l, int r){
    if(l == r) return; //no modifications needed
    else{
        int m = (l+r)/2, ll = l, rl = m+1;
        merge(l, m); merge(m+1, r);
        int idx = l;
        int b[100005] = {};
        while(ll <= m && rl <= r){
            if(a[ll] <= a[rl]){ // <= as newer scores are placed nearer to the top
                b[idx++] = a[ll++];
            }
            else{
                ans += m - ll +1; //a fall of rank
                b[idx++] = a[rl++];
            }
        }
        //place any remaining numbers 
        while(ll <= m) b[idx++] = a[ll++];
        while(rl <= r) b[idx++] = a[rl++]; 
    
        while(l<= r) {
            a[l] = b[l]; //some wonky stuff happens if u do l++ here for some reason
            l++;
        }
    }
}
int main(){
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    ans = n; 
    merge(0, n-1);
    
    printf("%.2lf\n", (double) ans/n);

    return 0;
}
*/