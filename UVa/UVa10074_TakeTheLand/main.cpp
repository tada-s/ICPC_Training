#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)

int main(){
  int m, n;
  int mat[100 + 1][100 + 1];
  int maxSum[100 + 1][100 + 1];
  int colSum[100 + 1][100 + 1];
  int bestSum[100 + 1];
  scanf("%d%d", &m, &n);
  while(!(m == 0 && n == 0)){
    for(int i = 1; i <= m; i++){
      for(int j = 1; j <= n; j++){
	scanf("%d", &mat[i][j]);
	mat[i][j] = 1 - mat[i][j];
      }
    }

    // colSum
    for(int j = 1; j <= n; j++){
      colSum[0][j] = 0;
      for(int i = 1; i <= m; i++){
	colSum[i][j] = colSum[i - 1][j] + mat[i][j];
      }
    }

    int maxSize = -1;
    for(int i = 0; i <= m; i++){
      maxSum[i][0] = -INF;
    }
    for(int j = 0; j <= n; j++){
      maxSum[0][j] = -INF;
    }
    for(int i = 1; i <= m; i++){
      //bestSum
      for(int i2 = 1; i2 <= m; i2++){
	bestSum[i2] = 0;
      }

      for(int j = 1; j <= n; j++){
	int sum = -INF;
	for(int i2 = 1; i2 <= i; i2++){
	  int col = colSum[i][j] - colSum[i2 - 1][j];
	  //printf("col[%d-%d][%d] sums %d\n", i, i2, j, col);
	  if(col == (i - i2 + 1)){
	    bestSum[i2] = bestSum[i2] + col;
	  }else{
	    bestSum[i2] = 0;
	  }
	  // bestSum[i2] = max(bestSum[i2] + col, col);
	  sum = max(sum, bestSum[i2]);
	}
	sum = max(sum, maxSum[i - 1][j]);
	sum = max(sum, maxSum[i][j - 1]);
	maxSum[i][j] = sum;
      }

      
    }
    

    printf("%d\n", maxSum[m][n]);
    
    scanf("%d%d", &m, &n);
  }
  return 0;
}
