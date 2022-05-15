// 11136 by xxepiccoder42069 gamer asum 

#include <cstdio>
#include <set>

using namespace std; 
//genius plan by malwart
//why are the numbers so big? :(
int main(){
    int d; 
    while(scanf("%d", &d), d){
        multiset<int, greater<int>> bills; 
        long long total = 0; 
        while(d--){
            int nb; 
            scanf("%d", &nb); 
            while(nb--){
                int b; 
                scanf("%d", &b); 
                bills.insert(b); 
            }
            multiset<int, greater<int>>::iterator big;;
            multiset<int, greater<int>>::iterator small; 
            big = bills.begin(); small = bills.end();
            small--;  
            total+= *big - *small; 
            big = bills.erase(big); small = bills.erase(small); 

        } 
        printf("%lld\n", total);
    }
    return 0; 
}