/*
ECOO 16 R1 P4
ray
AC
*/

#include <cstdio>
#include <algorithm>
#include <set>
#include <iostream>
//current plan: iterative brute force bash
//im not accounting for empty points!
using namespace std; 
struct House{
    int x; int y;
    char a;  
};
int main(){
    int TC = 10; 
    while(TC--){
        int x, y; scanf("%d %d\n", &x, &y); //starting house location
        int n = 100; 
        House h[n]; set<pair<int, int>> taken; 
        for(int i =0; i < n; i++){ 
            scanf("%d %d %c\n", &h[i].x, &h[i].y, &h[i].a);
            taken.insert(make_pair(h[i].x, h[i].y));
        }
        double r=0, d=0; 
        for(int i = -200; i <= 200; i++){
            for(int j = -200; j <= 200; j++){
            	int ix = i-x; int jx = j-y; 
                if((ix * ix) + (jx * jx) <=  2500 && taken.count(make_pair(i,j)) == 0){
                    pair<int,int> dist[n]; 
                    for(int k = 0; k < n; k++){
                    	int iy = i-h[k].x; int jy =j-h[k].y; 
                        dist[k].first = (iy * iy) + (jy * jy); 
                        dist[k].second = k; 
                        //printf("House %d is %d away from %d %d\n", dist[k].second, dist[k].first, i, j);
                    }
                    sort(dist, dist+n);
                    int ind = 0; int hr = 0, hd= 0; 
                    while(dist[ind].first <= dist[2].first && ind < n){
                    	//printf("Third furthest is house %d with distance %d, and it is %c\n", dist[ind].second, dist[ind].first, h[dist[ind].second].a);
                        if(h[dist[ind].second].a == 'D'){
                            hd++; 
                        }
                        else hr++;
                        ind++;
                    }
                    if(hd >= hr) d++; 
                    else r++;
                    
                }
            }
        }
        double ans = (d/(d+r)); 
        printf("%.1lf\n", ans*100.0);
    }
    return 0; 
}