/*
ccc 07 s4 
AC
*/

#include <cstdio>
#include <vector>

using namespace std; 

vector<int> adjl[10000]; 
int n, ans[10000];

//attempt 2 

int main(){
    //scan in number of nodes
    scanf("%d", &n);

    int a, b; //two vertices
    while(scanf("%d %d", &a, &b), a ){//while edges are given
        //a can go to b
        adjl[a].push_back(b);
    }

    ans[n] = 1; // there is ONE way to reach the bottom node from the bottom
    for(int i = n-1; i >= 1; i--){
        //move up the slide
        for(int v : adjl[i]){
            //for every node, you sum the number of ways to reach bottom from the nodes that you can visit from this node (this makes a lot of sense lol)
            ans[i] += ans[v];
        }
    }

    printf("%d", ans[1]); //number of ways to reach bottom node from starting node
    return 0;
}