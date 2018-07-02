#include <bits/stdc++.h>

using namespace std;

int getsum(int v[], int n){
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += v[i];
  }
  return 2 * sum;
}

int main(){
  int n;
  scanf("%d", &n);
  int v[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &v[i]);
  }
  
  sort(v, v + n);

  int sum = getsum(v, n);
  int goal = n * 9;
  int redo = 0;
  while(getsum(v,n) < goal){
    v[redo] = 5;
    redo++;
  }

  printf("%d\n", redo);
  
  
  return 0;
}
