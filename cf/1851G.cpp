/*
1851G
AC
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

vector<long long> h, dsu;

long long find(int a){
    if(dsu[a] == a) return a; 
    return dsu[a] = find(dsu[a]); 
}

void join(int a, int b){
    int x = find(a), y = find(b); 
    dsu[x] = y;
}

struct query
{
    int a;
    int b; 
    int e; 
};

int main(){
    
    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m; 
        h = vector<long long>(n); 
        vector<pair<int, int>> edges(m); 
        for(int i = 0; i < n; i++) cin >> h[i];
        for(int i = 0; i < m; i++) {
            cin >> edges[i].first >> edges[i].second;
            --edges[i].first; --edges[i].second;
        }
        

        int qs; 
        cin >> qs; 
        vector<int> ans(qs, 0);
        vector<pair<query, int>> q(qs);

        for(int i = 0; i < qs; i++){
            cin >> q[i].first.a >> q[i].first.b >> q[i].first.e;
            --q[i].first.a; --q[i].first.b; 
            q[i].second = i; 
        }

        sort(edges.begin(), edges.end(), [](pair<int, int> e1, pair<int, int> e2){
            return max(h[e1.first], h[e1.second]) < max(h[e2.first], h[e2.second]);
        });
        sort(q.begin(), q.end(), [](pair<query, int>& a, pair<query, int> &b){
            return h[a.first.a] + a.first.e < h[b.first.a] + b.first.e;
        });

        dsu = vector<long long>(n); 
        for(int i = 0; i < n; i++) dsu[i] = i; 
        int mxh = 0, j = 0;

        for(int i = 0; i < qs; i++){
            //cout << h[q[i].first.a] << " " << q[i].first.b << " " <<q[i].first.e << "\n"; 
            mxh = h[q[i].first.a] + q[i].first.e;
            while(j < m){
                if(max(h[edges[j].first], h[edges[j].second]) > mxh) break; 
                join(edges[j].first, edges[j].second); 
                j++;
            }
            ans[q[i].second] = find(q[i].first.a) == find(q[i].first.b);
        }

        for(int i = 0; i < qs; i++){
            if(ans[i]) cout << "YES\n"; 
            else cout << "NO\n";
        }
        cout << "\n";
    }
    return 0;
}