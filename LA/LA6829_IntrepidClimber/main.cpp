#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

#define pb push_back
#define mkp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, f;
int totalW;
vii nodes[(int) 1e5 + 100];
bool isFriend[(int) 1e5 + 100];

bool setFriend(int n){
  bool f = false;
  for(int i = 0; i < nodes[n].size(); i++){
    bool ff = setFriend(nodes[n][i].first);
    f = f || ff;
  }
  isFriend[n] = f || isFriend[n];
  return isFriend[n];
}

int getMaxW(int n){
  int maxW = 0;
  for(int i = 0; i < nodes[n].size(); i++){
    if( isFriend[ nodes[n][i].first ] ){
      totalW += nodes[n][i].second;
      int w = getMaxW( nodes[n][i].first );
      maxW = max( maxW, w + nodes[n][i].second );
    }
  }
  return maxW;
}


void init(){
  totalW = 0;
  for(int i = 0; i <= n; i++){
    nodes[i].clear();
    isFriend[i] = false;
  }
}

int main(){
  scanf("%d %d", &n, &f);
  while(!feof(stdin)){
    init();
    for(int i = 0; i < n-1; i++){
      int a,b,c;
      scanf("%d %d %d", &a, &b, &c);
      nodes[a].pb( mkp(b,c) );
    }
    for(int i = 0; i < f; i++){
      int ff;
      scanf("%d",&ff);
      isFriend[ff] = true;
    }
    setFriend(1);
    int maxW = getMaxW(1);
    int delta = totalW - maxW;
    printf("%d\n", delta);
    scanf("%d %d", &n, &f);
  }

  return 0;
}
