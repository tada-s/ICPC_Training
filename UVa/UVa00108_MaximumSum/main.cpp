#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  int mat[100][100];
  int sum[100 + 1][100 + 1];
  while(scanf("%d", &n) != EOF){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
	scanf("%d", &mat[i][j]);
      }
    }
    for(int i = 0; i < n; i++){
      sum[i][0] = 0;
      sum[0][i] = 0;
    }
    for(int i = 0 ; i < n; i++){
      for(int j = 0; j < n; j++){
	sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];
      }
    }

    int maxS = -(1<<29);
    for(int i0 = 0; i0 < n; i0++){
      for(int j0 = 0; j0 < n; j0++){
	for(int i1 = i0; i1 < n; i1++){
	  for(int j1 = j0; j1 < n; j1++){
	    int s = sum[i1 + 1][j1 + 1] - sum[i0][j1 + 1] - sum[i1 + 1][j0] + sum[i0][j0];
	    maxS = max(maxS, s);
	  }
	}
      }
    }

    printf("%d\n", maxS);
  }
  
  return 0;
}
