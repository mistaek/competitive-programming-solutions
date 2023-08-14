#include <cstdio>
#include <vector>

using namespace std; 

//trying out classes
class DisjointSet {
    private: vector<int> p, rank;
    public: DisjointSet(int n) {p.assign(n, 0); rank.assign(n, 0); for(int i = 0; i < n; i++) p[i] = i;};
    // an equals sign messed me up!
    int findSet(int i ){return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
    bool sameSet(int i, int j) {return findSet(i) == findSet(j);}
    void uniteSet(int i, int j){
        //if(!sameSet(i, j)){ needed?
            int pi = findSet(i); int pj = findSet(j); 
            if(rank[pi] > rank[pj]) p[pj] = p[pi];
            else{
                p[pi] = p[pj]; 
                if(rank[pi] == rank[pj]) rank[pj]++; 
            }
        //}
    }
    bool connected(){
        vector<int>::iterator it, initial = p.begin(); 
        for(it = p.begin(); it!= p.end(); it++){
            if(*it != *initial && it != p.end()){ printf("Disconnected Graph"); return false;}
        }
        return true; 
    }
};

int main(){
    int n, m; 
    scanf("%d %d", &n, &m);
    DisjointSet ds(n); 
    vector<int> elist; 
    for(int i = 1; i <= m; i++){
        int v1, v2; scanf(" %d %d", &v1, &v2); 
        v1--; v2--; 
        if(!ds.sameSet(v1, v2)){
            ds.uniteSet(v1, v2); 
            elist.push_back(i); 
        }
    }
    if(ds.connected()){
         for(vector<int>::iterator it = elist.begin(); it!= elist.end(); it++) printf("%d\n", *it);
    }
    return 0; 
}