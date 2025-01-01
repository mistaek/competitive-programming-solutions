/*
2053D.cpp
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std; 

long long MOD = 998244353;
vector<long long> a, b; 
vector<long long> sa, sb; 




long long binexp(long long a, long long exp){
    long long ans = 1, pow = a; 
    for(int i = 0; i < 30; ++i){
        if(exp & (1LL << i)) ans *= pow; 
        ans %= MOD; 
        pow *= pow;
        pow %= MOD; 
    }
    return ans; 
}

/*
void test(){
    srand(time(0));
    while(true){
    int n = rand() % 5 + 1, q = rand() % 5 + 1; 
    a = b = vector<pair<long long, int>>(n); 
    vector<int> sa, sb, oga, ogb; 
    long long prod = 1;
    for(int i = 0; i < n; ++i){
        a[i].first = rand() % 10 + 1; a[i].second = i+1; 
        sa.push_back(a[i].first); 
    }   
    for(int i = 0; i < n; ++i){
        b[i].first = rand() % 10 + 1; b[i].second = i+1; 
        sb.push_back(b[i].first); 
    }
    oga = sa; ogb = sb; 
    sort(a.begin(), a.end()); 
    sort(b.begin(), b.end()); 
    for(int i = 0; i < n; ++i){
        ai[a[i].second] = i; 
        bi[b[i].second] = i; 
        prod *= min(a[i].first, b[i].first); 
        prod %= MOD; 
    }

    vector<int> og; 
    og.push_back(prod); 
    vector<pair<int, int>> sq; 
    for(int qt = 0; qt < q; ++qt){
        int o, x; 
        o = rand() % 2 + 1; 
        x = rand() % n + 1;
        sq.push_back({o, x});
        if(o == 1){
            //divide for now
            int ind = ai[x];
            prod *= binexp(min(a[ind].first, b[ind].first), MOD-2);
            prod %= MOD; 
            if(ind < n-1) prod *= binexp(min(a[ind+1].first, b[ind+1].first), MOD-2);
            prod %= MOD;
            //upd values
            a[ind].first++; 
            if(ind != n-1 && a[ind] > a[ind+1]){
                swap(a[ind], a[ind+1]);
                //upd index map
                ai[a[ind].second] = ind; 
                ai[a[ind+1].second] = ind+1; 
            }
            prod *= min(a[ind].first, b[ind].first);
            prod %= MOD; 
            if(ind < n-1) prod *= min(a[ind+1].first, b[ind+1].first); 
            prod %= MOD;
        }
        if(o == 2){
            int ind = bi[x];
            prod *= binexp(min(a[ind].first, b[ind].first), MOD-2);
            prod %= MOD;
            if(ind < n-1) prod *= binexp(min(a[ind+1].first, b[ind+1].first), MOD-2);
            prod %= MOD;
            //upd values
            b[ind].first++; 
            if(ind != n-1 && b[ind] > b[ind+1]){
                swap(b[ind], b[ind+1]);
                //upd index map
                bi[b[ind].second] = ind; 
                bi[b[ind+1].second] = ind+1; 
            }
            
            prod *= min(a[ind].first, b[ind].first);
            prod %= MOD; 
            if(ind < n-1) prod *= min(a[ind+1].first, b[ind+1].first); 
            prod %= MOD;
        }

        og.push_back(prod);
    }

    //brute 

    vector<int> brute; 
    for(int qt = 0; qt <q+1; ++qt){
        vector<int> sorteda = sa; 
        vector<int> sortedb = sb; 
        sort(sorteda.begin(), sorteda.end());
        sort(sortedb.begin(), sortedb.end()); 
        long long prod = 1; 
        for(int i = 0; i < n; ++i){
            prod *= min(sortedb[i], sorteda[i]); 
            prod %= MOD; 
        }
        brute.push_back(prod);
        if(qt < q){
            if(sq[qt].first == 1){
                sa[sq[qt].second - 1]++;
            }
            else sb[sq[qt].second - 1]++;
        }
    }

    bool found = false; 
    for(int i = 0; i < q + 1; ++i){
        if(brute[i] != og[i]){
            cout << n << " " << q << "\n"; 
            for(int i = 0; i < n; ++i){
                cout << oga[i] << " "; 
            }
            cout << "\n"; 
            for(int i = 0; i < n; ++i){
                cout << ogb[i] << " "; 
            }
            cout << "\n"; 
            for(int i = 0; i < q; ++i){
                cout << sq[i].first << " " << sq[i].second << "\n"; 
            }
            cout << "\n"; 
            for(int i = 0; i < q + 1; ++i){
                cout << og[i] << " " << brute[i] << "\n";
            }
            found = true; 
            break; 
        }
    }
    if(found) break; 
}

}*/

int main(){
    //test(); 
    //return 0;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t; cin >> t; 
    while(t--){
        int n, q; cin >> n >> q; 
        a = b = vector<long long>(n);
        long long prod = 1;
        for(int i = 0; i < n; ++i){
            cin >> a[i]; 
        }   
        for(int i = 0; i < n; ++i){
            cin >> b[i];
        }
        sa = a; sb = b; 
        sort(sa.begin(), sa.end()); 
        sort(sb.begin(), sb.end()); 
        for(int i = 0; i < n; ++i){
            prod *= min(sa[i], sb[i]); 
            prod %= MOD; 
        }

        cout << prod;

        for(int qt = 0; qt < q; ++qt){
            int o, x; cin >> o >> x; 
            x--;
            if(o == 1){
                long long v = a[x]; 
                auto it = prev(lower_bound(sa.begin(), sa.end(), v+1)); //current position 
                int ind = it - sa.begin();
                prod *= binexp(min(sa[ind], sb[ind]), MOD-2); 
                prod %= MOD; 
                (*it)++;
                prod *= min(sa[ind], sb[ind]);
                prod %= MOD;
                a[x]++; 
            }
            if(o == 2){
                long long v = b[x]; 
                auto it = prev(lower_bound(sb.begin(), sb.end(), v+1)); //current position 
                int ind = it - sb.begin();
                prod *= binexp(min(sa[ind], sb[ind]), MOD-2); 
                prod %= MOD; 
                (*it)++;
                prod *= min(sa[ind], sb[ind]);
                prod %= MOD; 
                b[x]++; 
            }

            cout << " " << prod;
        }
        cout << "\n";


    }

    return 0;
}