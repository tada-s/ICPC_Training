#include <bits/stdc++.h>

using namespace std;

#define repSTL(c, iter) for(typeof(c.begin()) iter = c.begin(); iter != c.end(); iter++)
#define mkp make_pair
#define pb push_back
#define INF 1<<29

typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m, s, t;
vii adjList[20000];

int dijkstra(){
  int dist[20000];
  for(int i = 0; i < n; i++){
    dist[i] = INF;
  }
  dist[s] = 0;
  priority_queue<ii, vii, greater<ii> > pq;
  pq.push(mkp(0, s));
  while(!pq.empty()){
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if(d == dist[u]){
      repSTL(adjList[u], iter){
	int w = iter->first;
	int v = iter->second;
	if(dist[u] + w < dist[v]){
	  dist[v] = dist[u] + w;
	  pq.push(mkp(dist[v], v));
	}
      }
    }
  }
  return dist[t];
}

int main(){
  freopen("input.txt", "r", stdin);
  int nn;
  scanf("%d", &nn);
  for(int nnn = 1; nnn <= nn; nnn++){
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for(int i = 0; i < n; i++){
      adjList[i].clear();
    }
    for(int i = 0; i < m; i++){
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      adjList[u].pb(mkp(w, v));
      adjList[v].pb(mkp(w, u));
    }
    int ans = dijkstra();
    if(ans == INF){
      printf("Case #%d: unreachable\n", nnn);
    }else{
      printf("Case #%d: %d\n", nnn,ans);
    }
  }
  return 0;
}
