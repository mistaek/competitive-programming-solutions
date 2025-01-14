/*
Convex Hull
mostly copied from usaco guide
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

pair<long long, long long> operator-(const pair<long long, long long>&l, const pair<long long, long long>& r){
    return {l.first - r.first, l.second - r.second};
}

long long zcross(const pair<long long, long long>& l, const pair<long long, long long>& r){
    return l.first * r.second - l.second * r.first; 
}

long long zcross(const pair<long long, long long>& p, const pair<long long, long long>& l, const pair<long long, long long>& r){
    return zcross(l - p, r -p);
}

long long norm(const pair<long long, long long>& p){
    return p.first * p.first + p.second * p.second; 
}

vector<long long> convexHull(vector<pair<long long, long long>>& pts){
    int pivot = (int)(min_element(pts.begin(), pts.end()) - pts.begin()); //leftest and bottomest polong long 
    vector<long long> candidates, hull{pivot}; 
    for(long long i = 0; i < (int)pts.size(); ++i){
        if(pts[i] != pts[pivot]) candidates.push_back(i); 
    }

    sort(candidates.begin(), candidates.end() , [&](long long a, long long b){
        long long z = zcross(pts[pivot], pts[a], pts[b]); 
        return ((z != 0) ? (z > 0) : (norm(pts[a]-pts[pivot]) < norm(pts[b] - pts[pivot]))); 
    }
    );

    for(auto& p : candidates){
        while(hull.size() > 1 && zcross(pts[end(hull)[-2]], pts[hull.back()], pts[p]) <= 0){
            hull.pop_back();
        }
        hull.push_back(p);
    }
    return hull;
}

//monochain
vector<pair<long long, long long>> convexHullMontoneChain(vector<pair<long long, long long>>& pts){
    vector<pair<long long, long long>> hull; 
    sort(pts.begin(), pts.end()); 
    pts.erase(unique(pts.begin(), pts.end()), pts.end()); 

    if(pts.size() < 3){
        return pts; 
    }

    //lower hull
    int n = pts.size(); 
    for(int i = 0; i < n; ++i){
        while(hull.size() > 1 && zcross(hull.end()[-2], hull.back(), pts[i]) <= 0) hull.pop_back();
        hull.push_back(pts[i]);
    }

    int lhs = hull.size(); //lower hull size

    for(int i = n-2; i >= 0; --i){
        while(hull.size() > lhs && zcross(hull.end()[-2], hull.back(), pts[i]) <= 0) hull.pop_back(); 
        hull.push_back(pts[i]); 
    }
    hull.pop_back(); 
    return hull;
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    long long n; 
    while(cin >> n){
        if(!n) break;  
        vector<pair<long long, long long>> pts(n); 
        for(long long i = 0; i < n; ++i){
            cin >> pts[i].first >> pts[i].second; 
        }

        /* solution 1
        vector<long long> hull = convexHull(pts); 
        cout << hull.size() << "\n";
        for(auto ind : hull){
            cout << pts[ind].first << " " << pts[ind].second << "\n";
        }
        */

        ///* solution 2
        vector<pair<long long, long long>> hull = convexHullMontoneChain(pts); 
        cout << hull.size() << "\n"; 
        for(auto& pt : hull){
            cout << pt.first << " " << pt.second << "\n";
        }
        //*/
    }
    return 0;
}