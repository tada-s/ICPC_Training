#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF (1<<29)

int main(){
    //freopen("input.txt", "r", stdin);

    int n;
    int casen = 1;
    scanf("%d", &n);
    while(n != 0){
        map< int, vector<int> > m;
        for(int i = 0; i < n; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            m[u].pb(v);
            m[v].pb(u);
        }

        int node, t;
        scanf("%d%d", &node, &t);
        while(!(node == 0 && t == 0)){
            map<int, int> dist;
            for(__typeof(m.begin()) iter = m.begin(); iter != m.end(); iter++){
                dist[iter->first] = INF;
            }

            queue<int> q;
            dist[node] = 0;
            q.push(node);

            while(!q.empty()){
                int u = q.front();
                q.pop();
                if(dist[u] <= t){
                    vector<int> adj = m[u];
                    for(int i = 0; i < adj.size(); i++){
                        int v = adj[i];
                        if(dist[v] > dist[u] + 1){
                            dist[v] = dist[u] + 1;
                            q.push(v);
                        }
                    }
                }
            }

            int c = 0;
            for(__typeof(m.begin()) iter = m.begin(); iter != m.end(); iter++){
                //printf("dist[%d] == %d\n", iter->first, dist[iter->first]);
                if(dist[iter->first] > t){
                    c++;
                }
            }

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", casen, c, node, t);
            casen++;

            scanf("%d%d", &node, &t);
        }

        scanf("%d", &n);
    }
    return 0;
}
