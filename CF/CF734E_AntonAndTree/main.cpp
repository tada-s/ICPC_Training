#include <bits/stdc++.h>

using namespace std;

#define INF 1<<29

vector< vector<int> > g(200000);
int color[200000];
bool visitado[200000];
int etiqueta[200000];

int minPaint(int u){
    visitado[u] = true;

    int paint = 0;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];

        if(!visitado[v]){
            if(color[u] == color[v]){
                paint = max(paint, minPaint(v));
            }else{
                paint = max(paint, minPaint(v) + 1);
            }
        }
    }

    return paint;
}

int main(){
    freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &color[i]);
    }

    for(int i = 0; i < n - 1; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i < n; i++){
        etiqueta[i] = 0;
        visitado[i] = false;
    }

    priority_queue< pair<int, int> > pq;
    for(int i = 0; i < n; i++){
        if(g[i].size() == 1){
            etiqueta[i] = 1;
            pq.push(make_pair(-1, i));
        }
    }

    while(!pq.empty()){
        int e = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(!visitado[u] && etiqueta[u] == e){
            visitado[u] = true;
            //etiqueta[u] = e;
            for(int i = 0 ; i < g[u].size(); i++){
                int v = g[u][i];
                if(!visitado[v]){
                    etiqueta[v] = max(etiqueta[v], etiqueta[u] + 1);
                    pq.push(make_pair(-etiqueta[v], v));
                }
            }
        }
    }

    int maxEtiqueta = 0;
    for(int i = 0; i < n; i++){
        maxEtiqueta = max(maxEtiqueta, etiqueta[i]);
    }

    int m = 0;
    for(int i = 0; i < n; i++){
        printf("%d etiqueta %d\n", i + 1, etiqueta[i]);

        if(etiqueta[i] == maxEtiqueta){
            for(int j = 0; j < n; j++){
                visitado[j] = false;
            }
            m = max(m, minPaint(i));
        }
    }

    printf("%d\n", m);

    return 0;
}
