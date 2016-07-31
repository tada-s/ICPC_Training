//Edmonds Karp O(V * E^2)
#include <bits/stdc++.h>
using namespace std;
#define repSTL(c, iter) for(typeof(c.begin()) iter = c.begin(); iter != c.end(); iter++)
#define pb push_back
#define INF 1<<29

map<int, int> p; // parent map to reconstruct path
int f, s, t; // global variables
#define arraySize 100
int AdjMat[arraySize][arraySize];
vector<int> AdjList[arraySize];
void augmentPath(int v, int minEdge) {
  if (v == s) { // managed to get back to source
    f = minEdge; // minEdge of the path
    return;
  }
  else if (p.count(v)) { // augment if there is a path
    // we need AdjMat for fast lookup here
    augmentPath(p[v], min(minEdge, AdjMat[p[v]][v]));
    AdjMat[p[v]][v] -= f; // forward edges -> decrease
    AdjMat[v][p[v]] += f; // backward edges -> increase
  }
}

void init(){
  /* ( vertex_number )
   * - edge_capacity -
   *  source 0, sink 3
   * 
   * (0)-----30----(1)
   *  |           / |
   *  |         /   |
   * 70       /     |
   *  |     5       |
   *  |   /         |
   *  | /           |
   * (2)-----25----(3)
   * 
   */
  AdjList[0].pb(1); AdjList[0].pb(2);
  AdjList[1].pb(0); AdjList[1].pb(2); AdjList[1].pb(3);
  AdjList[2].pb(0); AdjList[2].pb(1); AdjList[2].pb(3);
  AdjList[3].pb(1); AdjList[3].pb(2);
  AdjMat[0][1] = 30; AdjMat[1][0] = 30;
  AdjMat[0][2] = 70; AdjMat[0][2] = 70;
  AdjMat[1][2] = 5; AdjMat[2][1] = 5;
  AdjMat[1][3] = 70; AdjMat[3][1] = 70;
  AdjMat[2][3] = 25; AdjMat[3][2] = 25;
  s = 0;
  t = 3;
}

int main(){
  init();
  int max_flow = 0;
  while (1) { // this will be run max O(VE) times
    f = 0;
    queue<int> q; map<int, int> dist; // O(E) BFS and record path p
    q.push(s); dist[s] = 0; // start from source
    while (!q.empty()) {
      int u = q.front(); q.pop(); // queue: layer by layer!
      if (u == t) break; // modification 1: reach sink t, stop BFS
      repSTL (AdjList[u], v) // for each neighbours of u
	// modification 2: also check AdjMat as edges may disappear
	if (AdjMat[u][*v] > 0 && !dist.count(*v)) {
	  dist[*v] = dist[u] + 1; // then v is reachable from u
	  q.push(*v); // enqueue v for next steps
	  p[*v] = u; // modification 3: parent of *v is u
	}
    }
    augmentPath(t, INF); // path augmentation in O(V)
    if (f == 0) break; // seems that we cannot pass any more flow
    max_flow += f;
  }
  printf("Max flow = %d\n", max_flow);
  return 0;
}
