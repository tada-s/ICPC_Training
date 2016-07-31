#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  char str[100][100];
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%s", str[i]);
  }

  int rMax = 0;
  for(int i = 0; i < n; i++){
    int r = 1;
    for(int j = i + 1; j < n; j++){
      if(strcmp(str[i], str[j]) == 0){
	r++;
      }
    }
    rMax = max(rMax, r);
  }
  printf("%d", rMax);
  return 0;
}
