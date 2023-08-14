/*
dmopc 19 7 p2
ray
wipwip
*/
#include <cstdio>
#include <vector> 

using namespace std; 
vector<pair<int, int>> out; 
int n = 0; 
int modit(int a){
    a += n; 
    return a %= n;
}
int main(){
    scanf("%d", &n);
    int want[n]; int sum = 0; 
    for(int i = 0; i < n; i++){
        scanf("%d", &want[i]);
        sum += want[i]; 
    }
    if(sum %2) printf("NO"); 
    else{
        int t = 0; int i = 0;
        while(sum > 0){
            if(i == n) break; 
            if(want[i]){
                if(want[modit(i+1)] >= want[i] && want[modit(i-1)] >= want[modit(i)]){
                	t++;
                    if(want[modit(i+1)] > want[modit(i-1)]){
                        want[modit(i-1)] -= want[i];
                        want[i] = 0;
                        sum -= want[i]+want[i]; 
                        out.push_back(make_pair(i, i-1));
                    }
                    else{
                        want[modit(i+1)] -= want[i]; 
                        want[i] = 0; 
                        sum -= want[i]+want[i]; 

                        out.push_back(make_pair(i, i+1)); 
                        i = modit(i+1); 
                    } 
                }
                
                else if (want[modit(i+1)] >= want[i]){
                    want[modit(i+1)] -= want[i]; 
                    want[i] = 0; 
                    sum -= want[i]+want[i]; 

                    t++; 
                    out.push_back(make_pair(i, i+1));
                    i = modit(i+1); 
                }
                else if(want[modit(i-1)] >= want[i]){
                    want[modit(i-1)] -= want[i];
                    want[i] = 0;
                    sum -= want[i]+want[i]; 

                    t++; 
                    out.push_back(make_pair(i, i-1)); 
                    i = modit(i+1); 
                }
                else i++;
            }
        }
        if(i == n) printf("NO"); 
        else{
            printf("%d\n%d\n", t, (int)out.size());
        for(pair<int, int> serve : out){
            printf("%d %d\n", serve.first, serve.second);
        }
        }
    }
    return 0;
}