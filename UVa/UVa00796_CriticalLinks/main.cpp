#include <bits/stdc++.h>

using namespace std;

#define MAX_NODE (100 + 5)

int mat[MAX_NODE][MAX_NODE];
int dfs_num[MAX_NODE];
int dfs_min[MAX_NODE];

int n;
int dfsCounter;

void calcBridge(int u){
    dfs_min = dfs_num[u] = dfsCounter++;
    for(v = 0; v < n; v++){
        if(mat[u][v]){
            calcBridge(v);
            if(dfs_min[v] > dfs_num[u]){

            }
            dfs_min[u] = min(dfs_min[u], dfs_min[v]);
        }
    }
}

int main(){

    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                mat[i][j] = false;
            }
            dfs_num[i] = -1;
            dfs_min[i] = -1;
        }


        for(int i = 0; i < n; i++){
            int s, m, v;
            scanf("%d (%d)", &s, &m);
            for(int j = 0; j < m; j++){
                scanf("%d", &v);
                mat[s][v] = true;
            }
        }

        dfsCounter = 0;
        calcBridge(intu);
    }

    return 0;
}
