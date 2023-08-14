/*
ccc06s3
ac // do it methodically, grindy question, also there is a better line intersect algorithm
*/

#include <cstdio>
#include <algorithm>

using namespace std; 

pair<double, double> lines[4000];

pair<double, double> xy[2];

pair<double, double> points[4000];
int ans = 0; 
int n;

pair<double, double> ligne(pair<double, double> p1, pair<double, double> p2){
    double m, b;
    if(p1.first != p2.first) m = (p2.second-p1.second)/(p2.first - p1.first); 
    else m = 10001;
    if(p1.first != p2.first) b = p1.second - (m*p1.first); 
    else b = p1.first; 
    return {m, b};
}

bool collide(pair<double, double> p1, pair<double, double> p2){
    if(p1.first > p2.first) swap(p1, p2); 
    if(xy[0].first >xy[1].first) swap(xy[0], xy[1]);
    if(p2.first < xy[0].first || p1.first > xy[1].first) return false;

    if(p1.second > p2.second) swap(p1, p2); 
    if(xy[0].second > xy[1].second) swap(xy[0], xy[1]);
    if(p2.second < xy[0].second || p1.second > xy[1].second) return false;

    pair<double, double> l1, l2; 
    l1 = ligne(xy[0], xy[1]); l2 = ligne(p1, p2);
    if(l1.first == 10001 && l2.first == 10001){
        return true;
    }
    else if(l1.first == 10001){
        double y = (l2.first * l1.second) + l2.second; 
        if(p1.second > p2.second) swap(p1, p2); 
        if(xy[0].second > xy[1].second) swap(xy[0], xy[1]);
        if(p1.second <= y && p2.second >= y && xy[0].second <= y && xy[1].second >=y) return true;
        else return false; 
    }
    else if(l2.first == 10001){
        double y = (l1.first * l2.second) + l1.second; 
        if(p1.second > p2.second) swap(p1, p2); 
        if(xy[0].second > xy[1].second) swap(xy[0], xy[1]);
        if(p1.second <= y && p2.second >= y && xy[0].second <= y && xy[1].second >=y) return true;
        else return false; 
    }
    else if(l1.first == l2.first){
        return (l1.second == l2.second); // ranges should have been dealt with already
    }
    else{
        double x, y;
        //ax + b = cx + d
        //a-c)x = d-b
        x = (l2.second-l1.second)/(l1.first-l2.first); 
        y = (l1.first * x) + l1.second;
        if(xy[0].first >xy[1].first) swap(xy[0], xy[1]);
        if(p1.first > p2.first) swap(p1, p2); 
        return(xy[0].first <= x && xy[1].first >= x && p1.first <= x && p2.first >= x);
    }


}

int main(){
    scanf("%lf %lf %lf %lf", &xy[0].first, &xy[0].second, &xy[1].first, &xy[1].second);
    
    int tc; scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            scanf("%lf %lf", &points[i].first, &points[i].second); 
        }
        
        for(int i = 0; i < n; i++){
            int i2= i-1; if(i2 == -1) i2 = n-1;
            if(collide(points[i], points[i2])){
                //printf("collided with %lf %lf to %lf %lf\n", points[i].first, points[i].second, points[i2].first, points[i2].second);
                ans++; 
                break;
            }
        }    
    }
    printf("%d\n", ans);
    return 0;
}