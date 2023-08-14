/*

*/

#include <cstdio>
#include<algorithm>
#include <map> 
#include <vector>


using namespace std; 
int main(){
    int TC; scanf("%d", &TC); 
    for(int tc = 1; tc <= TC; tc++){
       int n, k, ans = 0; scanf("%d %d", &n, &k);
       map<int, int> c; 
       vector<int> v, b; 
       for(int i = 0; i < n; i++){
           int in; scanf("%d", &in); 
           if(c.count(in) == 0){
               v.push_back(in); 
               c[in] = 1; 
           }
       }
       sort(v.begin(), v.end());

       b.push_back(v[0] - 1); // 1 consideration
       for(int i =0; i < v.size(); i++){
            if(i == v.size() - 1){
                b.push_back(k - v[i]);
            }
            else{
                b.push_back((v[i+1] - v[i])/2);
                ans = max(ans, v[i+1] - v[i] - 1);

            }
       }
       sort(b.begin(), b.end()); 
       ans = max(ans, b[b.size()-1] + b[b.size() - 2]);
       double out = (double) ans /k;
       printf("Case #%d: %.6lf\n",tc,  out);
        
        
    }
    return 0;
}