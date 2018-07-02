#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair
#define pb push_back
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
  int n;
  vii tPositive, tNegative;

  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    int x, a;
    scanf("%d %d", &x, &a);
    if(x > 0){
      tPositive.pb(mkp(x, a));
    }else{
      tNegative.pb(mkp(x, a));
    }
  }
  sort(tPositive.begin(), tPositive.end());
  sort(tNegative.rbegin(), tNegative.rend());

  int sum = 0;
  int u = min(tPositive.size(), tNegative.size());
  for(int i = 0; i < u; i++){
    sum += tPositive[i].second + tNegative[i].second;
  }
  if(tPositive.size() != u){
    sum += tPositive[u].second;
  }else if(tNegative.size() != u){
    sum += tNegative[u].second;
  }
  printf("%d\n", sum);
  return 0;
}
