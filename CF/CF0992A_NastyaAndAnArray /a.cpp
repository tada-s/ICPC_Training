#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  map<int, int> m;
  for(int i  =0; i < n; i++){
    int x;
    scanf("%d", &x);
    m[x] = 1;
  }
  m[0];
  printf("%d\n", m.size() - 1);
  
  return 0;
}
