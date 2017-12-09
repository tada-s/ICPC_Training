#include <bits/stdc++.h>

using namespace std;

#define MAX_K 30
#define UNDEF -1
#define pb push_back

int d[MAX_K];
vector<int> g[MAX_K];
  
bool cmp(int l[30][10], int n, int i, int j){
  for(int k = 0; k < n; k++){
    if(l[i][k] <= l[j][k]){
      return false;
    }
  }
  return true;
}

int f(int u){
  if(d[u] == UNDEF){
    int maxDepth = 1;
    for(int i = 0; i < g[u].size(); i++){
      int v = g[u][i];
      maxDepth = max(maxDepth, f(v) + 1);
    }
    d[u] = maxDepth;
  }
  
  return d[u];
}

void init(int k){
  for(int i = 0; i < k; i++){
    g[i].clear();
    d[i] = UNDEF;
  }
}

void printR(int u){
  if(g[u].size() == 0){
    printf("%d\n", u + 1);
  }else{
    printf("%d ", u + 1);
  }

  for(int i = 0; i < g[u].size(); i++){
    int v = g[u][i];
    if(f(v) + 1 == f(u)){
      printR(v);
      break;
    }
  }
}

int main(){
  //freopen("input.txt", "r", stdin);
  
  int k, n;
  while(scanf("%d %d", &k, &n) != EOF){
    int l[30][10];

    init(k);
    
    for(int i = 0; i < k; i++){
      for(int j = 0; j < n; j++){
	scanf("%d", &l[i][j]);
      }
    }

    for(int i = 0; i < k; i++){
      sort(l[i], l[i] + n);
    }
    
    for(int i = 0; i < k; i++){
      for(int j = 0; j < k; j++){
	if(cmp(l, n, i, j)){
	  g[j].pb(i);
	}
      }
    }

    for(int i = 0; i < k; i++){
      f(i);
    }

    int maxI = 0;
    for(int i = 0; i < k; i++){
      if(f(maxI) < f(i)){
	maxI = i;
      }
    }

    printf("%d\n", f(maxI));
    printR(maxI);
  }
  return 0;
}
