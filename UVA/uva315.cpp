/*
UVa 315
Ray
AC
pog!
*/

#include <cstdio>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
//detailed (hopefully) comments on this one as I am unfamiliar with articulation points/bridge algorithms.

using namespace std;
#define min(a, b) ((a < b) ? a : b)
vector<int> adjl[101];
int dfsn[101], dfsl[101], dfsr = 0, rchild = 0, ans = 0, dfscount = 0, dfsp[101]; //dfs arrays used to check for points  
bool av[101]; 

void dfs(int v){
    dfsn[v] = dfsl[v] = dfscount++; //set the counters equal to dfscount,then increment dfscount.
    //printf("dfsn[%d] is now %d\n", v, dfscount-1);
    for(auto it = adjl[v].begin(); it != adjl[v].end(); it++){
        if(dfsn[*it] == -1){
            dfsp[*it] = v; 
            if(v == dfsr) rchild++;
            dfs(*it);

            if(dfsl[*it] >= dfsn[v]) av[v] = true; //if dfs low is great/equal to dfsnum, this vertex is an articulation point.
            dfsl[v] = min(dfsl[v], dfsl[*it]); //update dfs low
        }
        else if(*it != dfsp[v]){ //back edge check
            dfsl[v] = min(dfsl[v], dfsn[*it]);
        }
    }
}
int main(){
    int n; //io to begin each case
    while(scanf("%d\n", &n), n){ //take the \n so getline doesn't mess up 
        // maintenance
        memset(dfsn, -1, sizeof(dfsn));
        memset(dfsp, -1, sizeof(dfsp));
        memset(dfsl, -1, sizeof(dfsl));
        memset(av, false, sizeof(av));
        ans = 0; 
        dfscount = 0;
        for(int i = 0; i < 101; i++) adjl[i].clear();


        //input
        int ind = 1; //current station
        stringstream ss; 
        string line; //get each line
        while(getline(cin, line), line[0] != '0'){
            //cout << line << endl;
            //add edges to the adjacency list
            ss << line; 
            // oops! misread input!
            int a,b; 
            ss >> a;
            while(ss >> b){
                //take ints, and put them into the adjl list.
                adjl[a].push_back(b);
                adjl[b].push_back(a);  
            }
            ind++;
            ss.clear();
        }

        //run dfs
        for(int i = 1; i <= n; i++){
            if(dfsn[i] == -1){// if unvisited
                //printf("Starting from node %d\n", i);
                //set dfs root to i, number of root children to 0, and the counter to 0
                dfsr = i; rchild = 0; 
                dfs(i); // run dfs on i 
                av[dfsr] = (rchild >1); // check if more than 1 root child exists for the articulation check.
            }
        }
        for(int i = 1; i <= n; i++) if(av[i]) ans++;
        printf("%d\n", ans); 


    }
    return 0; 
}