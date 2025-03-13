/*
1017E
AC poggin
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define f first 
#define s second

using namespace std; 
using pl = pair<long long, long long>; 

// determine if 2 convex hulls are equal up to isomorphism 

pl operator-(const pl& a, const pl& b){
    return {a.f - b.f, a.s - b.s};
}

long long zcross(const pl& a, const pl& b){
    return a.first * b.second - a.second * b.first; 
}

long long zcross(const pl& p, const pl&a, const pl&b){
    return zcross(a-p, b-p);
}

long long dot(const pl& a, const pl& b){
    return a.f * b.f + a.s * b.s; 
}

long long norm(const pl& p){
    return dot(p, p); 
}

vector<pl> grahamScan(vector<pl>& pts){
    pl pivot = *min_element(pts.begin(), pts.end());
    vector<pl> candidates, hull{pivot}; 
    for(auto& pt : pts) if(pt != pivot) candidates.push_back(pt);

    sort(candidates.begin(), candidates.end(), [&](pl a, pl b){
        long long z = zcross(pivot, a, b); 
        return z!=0 ? z > 0 : norm(a - pivot) < norm(b - pivot);  
    });

    for(auto& pt : candidates){
        while(hull.size() > 1 && zcross(hull.end()[-2], hull.back(), pt) <= 0) hull.pop_back();
        hull.push_back(pt); 
    }
    return hull; 
}

vector<pl> monoChain(vector<pl>& pts){
    sort(pts.begin(), pts.end()); 
    vector<pl> hull;
    int n = pts.size(); 

    for(int i = 0; i < n; ++i){
        while(hull.size() > 1 && zcross(hull.end()[-2], hull.back(), pts[i]) <= 0) hull.pop_back(); 
        hull.push_back(pts[i]); 
    }

    int lhs = hull.size(); 
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
    int n, m; cin >> n >> m; 
    vector<pl> pts1(n), pts2(m); 
    for(int i = 0; i < n; ++i) cin >> pts1[i].f >> pts1[i].s; 
    for(int i = 0; i < m; ++i) cin >> pts2[i].f >> pts2[i].s;

    vector<pl> hull1 = grahamScan(pts1), hull2 = monoChain(pts2); 

    //determine if hull1 and hull2 are the same under translation and rotation: look at length of edges and angle between pts

    if(hull1.size() != hull2.size()){
        cout << "NO\n"; // should be the same, we have discarded collinear points
        return 0;
    }
    n = hull1.size(); //reusing n lol

    vector<pl> h1, h2; //transform them
    for(int i = 0; i < n; ++i){
        pl pt1 = hull1[i], pt2 = hull1[(i+1) % n], pt3 = hull1[(i+n-1)%n]; //pt3 is previous pt
        h1.push_back({norm(pt1 - pt2), dot(pt3 - pt1, pt2 - pt1)});
        
        /*cout << "H1\n"; 
        cout << pt1.first << " " << pt1.second << " " << pt2.first << " " << pt2.second << " " << pt3.first << " " << pt3.second << "\n"; 
        cout << h1[i].f << " " << h1[i].s << "\n"; */

        pt1 = hull2[i], pt2 = hull2[(i+1) % n], pt3 = hull2[(i+n-1)%n]; //pt3 is previous pt
        h2.push_back({norm(pt1 - pt2), dot(pt3 - pt1, pt2 - pt1)});
        
        /*cout << "H2\n";
        cout << pt1.first << " " << pt1.second << " " << pt2.first << " " << pt2.second << " " << pt3.first << " " << pt3.second << "\n"; 
        cout << h2[i].first << " " << h2[i].second << "\n"; */
    }

    
    // we now run kmp

    vector<int> prefn(n, 0); //prefix function 
    for(int i = 1; i < n; ++i){
        int j = prefn[i-1];
        while(j && h2[i] != h2[j]){
            j = prefn[j-1]; 
        }
        if(h2[i] == h2[j]) ++j; 
        prefn[i] = j; 
    }
    //duplicate h1 
    for(int i = 0; i < n; ++i){
        h1.push_back(h1[i]); 
    }

    int matched = 0;
    for(int i = 0; i < 2*n; ++i){
        if(matched == n) break; 
        while(matched && h2[matched] != h1[i]) matched = prefn[matched-1];
        if(h2[matched] == h1[i]) ++matched; 
    }

    if(matched == n){
        cout << "YES\n";
    }
    else cout << "NO\n";

    return 0;
}