#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define pb push_back

#define MAXNODE 100
vi g[MAXNODE];
int flow[MAXNODE][MAXNODE];
int residual[MAXNODE][MAXNODE];
int capacity[MAXNODE][MAXNODE];

void setZero(){
    for(int i = 0; i < MAXNODE; i++){
        g[i].clear();
        for(int j = 0; j < MAXNODE; j++){
            flow[i][j] = 0;
            residual[i][j] = 0;
            capacity[i][j] = 0;
        }
    }
}

void getGraph(){
    g[0].pb(1); residual[0][1] = 9;
    g[0].pb(2); residual[0][2] = 9;
    g[1].pb(2); residual[1][2] = 10;
    g[1].pb(3); residual[1][3] = 8;
    g[2].pb(3); residual[2][3] = 1;
    g[2].pb(4); residual[2][4] = 3;
    g[3].pb(5); residual[3][5] = 10;
    g[4].pb(3); residual[4][3] = 8;
    g[4].pb(5); residual[4][5] = 7;
}

int source = 0;
int target = 5;

bool visited[MAXNODE];

void resetTrace(){
    for(int i = 0; i < MAXNODE; i++){
        visited[i] = false;
    }
}

int getAugmentingPath(int node){
    for(int i = 0; i < g[node].size(); i++){
        int v = g[node][i];
        printf("node [%d]->[%d] residual: %d\n", node, v, residual[node][v]);
        if(residual[node][v] > 0){
            if(visited[v] == false){
                if(v == target){
                    return residual[node][v];
                }else{
                    visited[v] = true;
                    int f = flowAugmentingPath(v);
                    visited[v] = false;
                    if(f != 0){
                        return min(f, residual[node][v]);
                    }
                }
            }
        }
    }
    return 0;
}

int maxflow(){
    int maxFlow = 0;
    int f;
    do{
        f = 0;
        resetTrace();
        f = flowAugmentingPath(source);
        maxFlow += f;
    }while(f != 0);
    return maxFlow;
}

int main(){
    setZero();
    getGraph();
    printf("Max Flow: [%d]\n", maxflow());
    return 0;
}
