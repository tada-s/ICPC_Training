#include <stdio.h>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int v[10] = {0,0,0,0,0,0,0,0,0,0};
    int x;
    scanf("%d", &x);
    for(int i = 1; i <= x; i++){
      int y = i;
      while(y != 0){
	v[ y % 10 ]++;
	y /= 10;
      }
    }
    for(int i = 0; i < 9; i++){
      printf("%d ", v[i]);
    }
    printf("%d\n", v[9]);
  }
  return 0;
}
