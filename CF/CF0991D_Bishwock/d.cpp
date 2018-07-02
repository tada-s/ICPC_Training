#include <bits/stdc++.h>

using namespace std;

int v[100 + 1];

int f(int n, int state){
  if(n <= 0){
    return 0;
  }else{
    switch(state){
    case 0:
      if(v[n - 1] == 2){
	return f(n - 1, v[n - 1]);
      }else{
	return f(n - 1, v[n - 1] + 1) + 1;
      }
      break;
    case 1:
      if(v[n - 1] >= 1){
	return f(n - 1, v[n - 1]);
      }else{
	return f(n - 1, v[n - 1] + 2) + 1;
      }
      break;
    case 2:
      return f(n - 1, v[n - 1]);
      break;
    }
  }
}

int main(){
  char board[2][100 + 2];
  scanf("%s", board[0]);
  scanf("%s", board[1]);
  int n = strlen(board[0]);
  for(int i = 0; i < n; i++){
    v[i] = (board[0][i] == '0' ? 0 : 1) + (board[1][i] == '0' ? 0 : 1);
  }
  printf("%d", f(n - 1, v[n - 1]));
  
  return 0;
}

