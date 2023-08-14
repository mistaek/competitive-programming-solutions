/* UVa 10172, overcounting somewhere*/
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int sets; 
    scanf("%d", &sets); 
    while(sets--){
        int time = 0, total =0;
        int n, ssz, qsz; 
        scanf("%d %d %d", &n, &ssz, &qsz); 
        stack<int> s; 
        queue<int> qs[n+1]; 
        int numobs[n+1] = {};
        int sN = 0; 
        int i; 
        for(i = 1; i <= n; i++){
            int q, o; 
            scanf("%d", &q);
            while(q--){
                scanf("%d", &o); 
                qs[i].push(o);
                numobs[i]++;
                total++;
            } 
            
        }
        i = 1; 
        while(total){
            if(i >n) i-= n; 
            while(!s.empty()){
                if(s.top() == i){
                    s.pop(); 
                    sN--; 
                    time++;
                    total--;
                }   
                else if(numobs[i] < qsz){
                    qs[i].push(s.top()); 
                    s.pop(); 
                    sN--;
                    numobs[i]++; 
                    time++;
                }
                else break; 
            }
            while(!qs[i].empty()){
                if(sN == ssz) break; 
                s.push(qs[i].front()); 
                sN++;   
                qs[i].pop(); 
                numobs[i]--;
                time++; 
            }
            i++;
            if(total)time+=2;
        }
        printf("%d\n", time); 
    }
    return 0; 
}