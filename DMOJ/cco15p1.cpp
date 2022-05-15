/*
cco 15 p1 
ray
AC
*/
//POG
//send points
#include <cstdio>
#include <algorithm>

using namespace std; 

#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

int abs(int a){
    if(a < 0) return -a; 
    else return a; 
}
int main(){

    long long n, w; scanf("%lld %lld", &n, &w); 
    long long c[n] = {}; 
    for(long long i = 0; i < n; i++){
        scanf("%lld", &c[i]);
    }
    sort(c, c+n); 
    //FIND MAX
    long long t = w;
    long long path1 =0, path2 = 0, hilo = 1; //1 take hisgh, 0 take low
    //path 1
    long long hind = n-1, lind = 0; 
    while(hind >= lind){
        if(hilo){
            hilo = 0; 
            path1 += max(abs(c[hind]-t), abs(c[hind]-w));
            t = c[hind]; 
            hind--;
        }
        else{
            hilo = 1; 
            path1 += max(abs(c[lind] - t), abs(c[lind] - w)); 
            t = c[lind];
            lind++;
        }
    }

    //path 2
    hind = n-1; lind = 0; hilo = 0; 
    while(hind >= lind){
        if(hilo){
            hilo = 0; 
            path2 += max(abs(c[hind]-t), abs(c[hind]-w));
            t = c[hind]; 
            hind--;
        }
        else{
            hilo = 1; 
            path2+=max(abs(c[lind] - t), abs(c[lind] - w)); 
            t = c[lind];
            lind++;
        }
    }

    //max 
    long long outmax = max(path1, path2);

    //FIND MIN
    long long outmin; 
    if(w <= c[n-1] && w >= c[0]) outmin = abs(w-c[0]) + abs(w - c[n-1]);
    else if(w < c[0]){
        outmin = abs(c[0] - w) + abs(c[n-1] - c[0]);
    }
    else{ 
        outmin = abs(c[n-1] - w) + abs(c[0] - c[n-1]);
    }
    printf("%lld %lld", outmin, outmax); 
    
    return 0; 
}