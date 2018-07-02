#include <bits/stdc++.h>

using namespace std;

int space[100 + 1][100 + 1];
int maxSum[100 + 1][100 + 1];
int bestSum[100 + 1];
int colSum[100 + 1][100 + 1];

int main(){
  int p;
  scanf("%d", &p);
  for(int pp = 0; pp < p; pp++){
    int s;
    scanf("%d", &s);
    for(int i = 1; i <= s; i++){
      for(int j = 1; j <= s; j++){
	space[i][j] = 1;
      }
    }
    
    int b;
    scanf("%d", &b);
    for(int bb = 0; bb < b; bb++){
      int r1, c1, r2, c2;
      scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
      for(int i = r1; i <= r2; i++){
	for(int j = c1; j <= c2; j++){
	  space[i][j] = 0;
	}
      }
    }

    for(int i = 0; i <= s; i++){
      colSum[i][0] = 0;
      colSum[0][i] = 0;
    }
    for(int j = 1; j <= s; j++){
      for(int i = 1; i <= s; i++){
	colSum[i][j] = colSum[i - 1][j] + space[i][j];
      }
    }
    
    for(int i = 0; i <= s; i++){
      maxSum[i][0] = 0;
      maxSum[0][i] = 0;
    }
    for(int i = 1; i <= s; i++){
      for(int i2 = 0; i2 <= i; i2++){
	bestSum[i2] = 0;
      }

      for(int j = 1; j <= s; j++){
	int sum = -1;
	for(int i2 = 1; i2 <= i; i2++){
	  int col = colSum[i][j] - colSum[i2 - 1][j];
	  if(col == (i - i2 + 1)){
	    bestSum[i2] += col;
	  }else{
	    bestSum[i2] = 0;
	  }
	  
	  sum = max(sum, bestSum[i2]);
	}

	sum = max(sum, maxSum[i - 1][j]);
	sum = max(sum, maxSum[i][j - 1]);
	maxSum[i][j] = sum;
      }
    }

    printf("%d\n", maxSum[s][s]);
    
  }
  
  return 0;
}
