#include <bits/stdc++.h>

using namespace std;

int f(int n){
  if(n == 0) return 1;
  if(n == 2) return 1;
  int sum = 0;
  for(int i = 0; i <= n - 2; i += 2){
    sum += f(i) * f(n - 2 - i);
  }
  return sum;
}

int main(){
  bool firstTime = true;
  int n;
  while(scanf("%d", &n) != EOF){
    if(firstTime){
      firstTime = false;
    }else{
      printf("\n");
    }
    printf("%d\n", f(2*n));
  }
  return 0;
}
