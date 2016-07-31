#include <bits/stdc++.h>

using namespace std;
#define repstl(iter, c) for(__typeof(c.begin()) iter = c.begin(); iter != c.end(); iter++)
#define INF 1<<29

map<int, int> p;
int f, s, t;
int AdjMat[105][105];
vector< pair<int,int> > AdjList[105];

void augmentPath(int v, int minEdge){
    if(v == s){
        f = minEdge;
        return;
    }
    else if(p.count(v)){
        augmentPath(p[v], min(minEdge,AdjMat[p[v]][v]));
        AdjMat[p[v]][v] -= f;
        AdjMat[v][p[v]] += f;
    }
}

int main(){
    int n;
    int test = 1;
    scanf("%d",&n);
    while(n != 0){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                AdjMat[i][j] = 0;
            }
        }
        int c;
        scanf("%d %d %d",&s,&t,&c);
        for(int i = 0; i < c; i++){
            int x,y,z;
            scanf("%d %d %d",&x, &y, &z);
            AdjMat[x][y] += z;
            AdjMat[y][x] += z;
            //AdjList[x].push_back(make_pair(y,z));
            //AdjList[y].push_back(make_pair(x,z));
        }

        int max_flow = 0;
        while(true){

            f = 0;
            queue<int> q;
            map<int, int> dist;
            q.push(s);
            dist[s] = 0;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                if(u == t) break;

                //repstl(v, AdjList[u]){     v->first
                for(int v = 1; v <= n; v++){
                    if(AdjMat[u][v] > 0 && !dist.count(v)){
                        dist[v] = dist[u] + 1;
                        q.push(v);
                        p[v] = u;
                    }
                }
            }
            augmentPath(t, INF);
            if(f == 0) break;
            max_flow += f;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n", test++, max_flow);

        for(int i = 0; i <= n; i++){
            if(AdjList[i].size() != 0) AdjList[i].clear();
        }
        p.clear();

        scanf("%d",&n);
    }
    return 0;
}
