#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define pb push_back

vi f;

int alterDigit(int n, int pos, int plus){
    int p = pow(10, pos);
    int d = (n / p) % 10;
    n = n - d * p;
    d = ((d + plus) + 10) % 10;
    n = n + d * p;
    return n;
}

int getInt(){
    int r = 0;
    for(int i = 0; i < 4; i++){
    int x;
        scanf("%d", &x);
        r = r * 10 + x;
    }
    return r;
}

int sssp(int s, int t){
    if(s == t) return 0;

    int dist[10000];
    bitset<10000> reach;
    #define INF 1<<29
    for(int i = 0; i < 10000; i++){
        dist[i] = INF;
    }
    reach.reset();
    for(int i = 0; i < f.size(); i++){
        reach.set(f[i]);
    }
    dist[s] = 0;

    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(!reach.test(u)){
            reach.set(u);
            for(int i = 0; i < 4; i++){
                int v = alterDigit(u, i, 1);
                if(!reach.test(v)){
                    dist[v] = min(dist[v], dist[u] + 1);
                    q.push(v);
                }
                v = alterDigit(u, i, -1);
                if(!reach.test(v)){
                    dist[v] = min(dist[v], dist[u] + 1);
                    q.push(v);
                }
            }
        }
    }
    return dist[t] == INF ? -1 : dist[t];
}

int main(){
    int a;
    scanf("%d", &a);
    for(int nn = 0; nn < a; nn++){
        int s = getInt();
        int t = getInt();
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            f.pb(getInt());
        }
        printf("%d\n",sssp(s,t));
        f.clear();
    }
    return 0;
}
