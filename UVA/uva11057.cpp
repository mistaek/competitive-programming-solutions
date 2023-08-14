#include <cstdio>
#include <vector>
#include <algorithm> 
#include <cmath>

using namespace std; 
//uva 11057 buy books good books 1 a week 52 books a year! 

//AC

int main(){
    int books; 
    while(scanf("%d", &books) != EOF){
        vector<int> prices(books, 0);
        for(int i = 0; i < books; i++){
            scanf("%d", &prices[i]); 
        }
        int money; scanf("%d", &money); 
        sort(prices.begin(), prices.end());
        
        /*for(auto p = prices.begin(); p!= prices.end(); p++) printf("%d ", *p); 
        printf("\n"); 
        printf("%d\n", money); 
        */
        pair<int, int> answer; int lowestd = 1000000; 
        for(int i = 0; i < books; i++){
            int c = count(prices.begin(), prices.end(), money - prices[i]); 
            //printf("prices[i]: %d, money - prices[i]: %d, occurences %d\n", prices[i], money - prices[i], c); 
            if(c && (money - prices[i] != prices[i] || c > 1)){
                if(lowestd > abs(money - prices[i] - prices[i])){
                    lowestd = money - prices[i] - prices[i];
                    answer.first = prices[i]; 
                    answer.second = money - prices[i];  
                }
            } 

        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", answer.first, answer.second);

    }
    return 0; 
}