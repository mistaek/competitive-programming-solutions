/*
2002D
*/

#include <iostream>
#include <vector>
#include <set>


using namespace std; 

int n, q; 
vector<int> p, pos, perm;
vector<int> subtsz;
//parents hold set of children which are out of order
int curr_nonempty = 0;
vector<set<int>> outoforder;


void update(int i, bool prop = false){
    int parent = p[i];
    int sz = subtsz[parent];
    if(i != 1 && pos[i] != pos[parent] + 1 && pos[i] != pos[parent] + sz + 1){
        if(outoforder[p[i]].size() == 0){
            ++curr_nonempty;

        }
        outoforder[p[i]].insert(i);
    }
    else{
        auto it = outoforder[p[i]].find(i);
        if(it != outoforder[p[i]].end()){
            outoforder[p[i]].erase(it); 
            if(outoforder[p[i]].size() == 0) --curr_nonempty;
        }
    }

    if(!prop) return; 
    // children are always 2*i and 2*i+1
    if((2*i)+1 <= n){
       update(2*i);
       update((2*i)+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc; 
    while(tc--){
        cin >> n >> q;
        p = vector<int>(n+1); 
        pos = vector<int>(n+1);
        perm = vector<int>(n+1);
        subtsz = vector<int>(n+1);
        outoforder = vector<set<int>>(n+1);
        curr_nonempty = 0;
        p[0] = 0;
        p[1] = 1; 
        subtsz[1] = (n-1)/2;
        for(int i = 0; i < n-1; ++i){
            cin >> p[i+2];
            subtsz[i+2] = (subtsz[p[i+2]] - 1)/2; 
        }

        for(int i = 0; i < n; ++i){
            cin >> perm[i+1];
            pos[perm[i+1]] = i+1;
        }
        for(int i = 0; i < n; ++i){
            update(i+1, true);
        }
        for(int i = 0; i < q; ++i){
            int x, y; cin >> x >> y;
            //cout << "swapping " << perm[x] << " " << perm[y] << "\n";
            swap(pos[perm[x]], pos[perm[y]]);
            swap(perm[x], perm[y]);
            update(perm[x], 1);
            update(perm[y], 1);
            //cout << curr_nonempty << "\n";
            if(curr_nonempty == 0) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}