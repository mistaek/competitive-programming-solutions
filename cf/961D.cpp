/*
961D
AC
*/
#include <iostream>
#include <vector>

using namespace std;

vector<pair<long long, long long>> pts; 
vector<pair<long long, long long>> pt(4);
vector<pair<long long, long long>> m(6), b(6);
long long ptmap[4][4] = {};

vector<long long> cts(6, 1);
void compute(int i, int j){
    int k = ptmap[i][j];
    m[k].first = pt[j].second - pt[i].second, m[k].second = pt[j].first - pt[i].first;
    b[k] = pt[i];
}

bool check(int i, int j){
    if(m[j].second == 0) return pts[i].first == b[j].first;

    long long rhs = m[j].first * (pts[i].first - b[j].first);
    if(rhs % m[j].second) return false;
    rhs /= m[j].second;
    return rhs == pts[i].second - b[j].second;     
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n; cin >> n; 
    pts = vector<pair<long long, long long>>(n);
    for(int i = 0; i < n; ++i){
        cin >> pts[i].first >> pts[i].second;
    }
    if(n < 3) {
        cout << "YES\n";
        return 0;
    }

    ptmap[0][1] = ptmap[1][0] = 0;
    ptmap[0][2] = ptmap[2][0] = 1; 
    ptmap[0][3] = ptmap[3][0] = 3; 
    ptmap[1][2] = ptmap[2][1] = 2; 
    ptmap[1][3] = ptmap[3][1] = 4; 
    ptmap[2][3] = ptmap[3][2] = 5;

    pt[0] = pts[0], pt[1] = pts[1];
    compute(0, 1);
    bool pos = true; 
    for(int i = 2; i < n; ++i){
        if(!check(i, 0)){
            pos = false; 
            pt[2] = pts[i];
            compute(1, 2);
            compute(0, 2); 
            break; 
        }
    }

    if(pos){
        cout << "YES\n"; return 0;
    }
    
    bool pt4made = false;
    for(int i = 0; i < n; ++i){
       bool pos1 = check(i, 0) || check(i, 1), pos2 = check(i, 1) || check(i, 2), pos3 = check(i, 0) || check(i, 2);
       if(!pos1 && !pos2 && !pos3){
            pt[3] = pts[i]; 
            compute(0, 3); 
            compute(1, 3);
            compute(2, 3); 
            pt4made = true;
            break;
       }
    }
    if(pt4made == false){
        pt[3] = pts[2]; 
        compute(0, 3); 
        compute(1, 3);
        compute(2, 3); 
    }


    for(int i = 0; i < 6; ++i){
        for(int j = i+1; j < 6; ++j){
            pos = true; 
            for(int k = 0; k < n; ++k){
                if(!check(k, i) && !check(k, j)){
                    pos = false; 
                    break; 
                }
            }
            if(pos) {
                break;
            } 
             
        }
        if(pos) break; 
    }
    if(pos){
        cout << "YES\n"; return 0;
    }
    cout << "NO\n";

    return 0;
}