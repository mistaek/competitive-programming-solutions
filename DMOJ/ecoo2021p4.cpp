/*
ecoo2021p4
ac IM CRACKED
*/
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std; 
int main(){
    long long k; scanf("%lld", &k);
    k++; 

    vector<pair<long long, long long>> facts; 
    long long count1 = 1, count3 = 0;
    for(int i = 2; i <= sqrt(k) +1; i++){
        long long count2 = 0;
        while(k%i == 0){ count2++; facts.push_back({count1++, i-1}); k /= i;}
        
        count3+= count2 *(i -1);
    }
    if(k != 1){ facts.push_back({count1++, k-1}); count3+= k-1;}
    
    if(count3 <= 100000 && count1 <= 100000 && !facts.empty()){
        printf("%d\n", count3);
        for(int i = 0; i < facts.size(); i++){
            for(int j = 0; j < facts[i].second; j++){
                if(i != 0 || j != 0) printf(" ");
                printf("%d", facts[i].first);
            }
        }
    }
    else printf("Sad Chris\n");
    return 0;
}