/* Final attempt for today */ 
#include <cstdio>

// six games are played
int wins = 0, team;

void calcWins(int p[5], bool pd[5][5]){
    bool pd1[5][5]; 
    int p1[5]; 
    for(int i = 0; i < 5; i++) p1[i] = p[i]; 
    for(int i = 0; i < 5; i++) 
        for(int j = 0; j < 5; j++) pd1[i][j] = pd[i][j]; 
    //why does this work lol
    for(int i = 1; i < 5; i++){ 
        for(int j = i+1; j <5; j++){
            if(!pd1[i][j]){
                pd1[i][j] = true; 
                pd1[j][i] = true; 
                p1[i] += 3; 
                calcWins(p1, pd1); 
                p1[i] = p[i]; 
                p1[j]+= 3; 
                calcWins(p1, pd1); 
                p1[j] = p[j]+1; 
                p1[i]++; 
                calcWins(p1, pd1); 
                return; 
            }
        }
    }   
    int best = 0, numBest = 1; 
    for(int i = 0;i<5; i++){
        if(p1[i] > best){
            best = p1[i]; 
            numBest = 1; 
        }
        else if(p1[i] == best) numBest++;
    }
    if(p1[team] == best && numBest == 1) wins++;  
}
int main(){
    int g; 
    int points[5] = {0, 0, 0, 0, 0};  
    bool played[5][5] = {};
    scanf("%d %d", &team, &g);
    // calculate games completed
    while(g--){
        int a, b, sa,sb; 
        scanf("%d %d %d %d", &a, &b, &sa, &sb);
        played[a][b] = true; 
        played[b][a] = true;  
        if(sa > sb) points[a]+= 3; 
        else if(sb > sa) points[b]+=3; 
        else{
            points[a]++; 
            points[b]++; 
        } 
    } 
    // processing
    calcWins(points, played); 
    //print answer
    printf("%d", wins); 
    return 0; 
}