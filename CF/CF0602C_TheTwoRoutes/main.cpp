#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 29)

bool adj[400 + 1][400 + 1];
int dist[400 + 1];
bool checked[400 + 1];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            adj[i][j] = false;
        }
        dist[i] = INF;
        checked[i] = false;
    }

    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u][v] = true;
        adj[v][u] = true;
    }

    if(adj[1][n] == true){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                adj[i][j] = !adj[i][j];
            }
        }
    }

    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(!checked[u]){
            checked[u] = true;
            for(int v = 1; v <= n; v++){
                if(adj[u][v] && !checked[v]){
                    dist[v] = min(dist[v], dist[u] + 1);
                    q.push(v);
                }
            }
        }
    }

    printf("%d", dist[n] == INF ? -1 : dist[n]);


    return 0;
}
