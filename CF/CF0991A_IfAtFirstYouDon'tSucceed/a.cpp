#include <bits/stdc++.h>

using namespace std;

int a, b, c, n;

int f(){
  int np = n - (a + b - c);
  if(!(a <= n - 1)) return -1;
  if(!(b <= n - 1)) return -1;
  if(!(c <= n - 1)) return -1;
  if(!(c <= a)) return -1;
  if(!(c <= b)) return -1;
  if(!(a + b - c <= n - 1)) return -1;
  return np;
}

int main(){
  
  scanf("%d%d%d%d", &a, &b, &c, &n);

  printf("%d\n", f());
  
  return 0;
}
