/*
* UVa 12032 - The Monkey and the Oiled Bamboo
* [NAME]
* AC
*/


#include <cstdio>

//binary search the answer
int heights[10000001], rungs; 

//test strengths
bool testk(int k){
    int cur = 0;
    for(int i = 0; i < rungs; i++){
        if(heights[i] - cur < k) cur = heights[i]; 
        else if(heights[i] - cur == k){cur = heights[i]; k--;} 
        else if(heights[i] - cur > k) return false;
    }
    return true; 
}

int main(){
    int TC; scanf("%d", &TC); 
    for(int loper = 1; loper<= TC; loper++){
        //input
        int max = 11000000; scanf("%d", &rungs);
        for(int i = 0; i < rungs; i++){
            scanf("%d", &heights[i]); 
        }
        //binary search
        int min = 0; 
        while(min < max){
            if(testk(max)){
                max = min +(max - min)/2;
            }
            else{
                min = max;
                max += max/2; 
            }
        }
        printf("Case %d: %d\n",loper, max+1);
    }
    return 0; 
}