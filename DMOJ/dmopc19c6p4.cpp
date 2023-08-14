/*
DMOPC 19 Grade 12 Math
BY RICHARD ZHANG MAH GOD
Ray
wipwip
*/

//ples save me 
//ok my segment trees are too weak, will work on tomrrow
#include <cstdio>
#include <vector>
#include <map> 

using namespace std; 



class segt{
    private:
    vector<map<int, int>> st; 
    int right(int a) return (a >> 1 | 1);
    int left(int a) return (a >> 1);
    int mid(int a, int b) return (a + b)/2;

    
    void build(int p, int l, int r){
        if(l == r){
            st[p][0] = 1;
        }
        else{
            build(left(p), l, mid(l, r));
            build(right(p)), mid(l,r) + 1, r); 

            st[p][0] += st[left(p)]; //we just add here because everything starts at 0
            st[p][0] += st[right(p)];
        }
    }
    int update(int p, int l, int r, int idx, int v){
        int ul = idx, ur = idx; //only one point is being updated, so we have the same update ranges
        if(r >= ul || l <= ur){
            //if range is involved
            if(r == idx && l == idx){
                //we have reached the index
                auto it = st[p].begin(); 
                st[p][it->first + v] = 1; 
                st[p].erase(it);
                return 2; 
            }
            else{
                int x1 = update(left(p), l, mid(l+r), idx, v); 
                int x2 = update(right(p), mid(l+r) + 1, r, idx, v); 

                if(x1){
                    for(auto it = st[left(p)].begin(); it!= st[left(p)].end(); it++){

                    }
                }
            }
        }
        else return 0;
    }

    public:
    egt(int N){
        st.assign(4*(N+1)); 
        op.assign(N+1);
        build(1, 0, N-1);
    }
}