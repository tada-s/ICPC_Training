#include <bits/stdc++.h>

using namespace std;

int mat[25][25];
int sum[25 + 1][25 + 1];

int main(){
  int t;
  scanf("%d", &t);
  for(int tt = 0; tt < t; tt++){
    char str[25 + 1];
    scanf("%s", str);
    int n = strlen(str);
    for(int j = 0; j < n; j++){
      mat[0][j] = str[j] - '0';
    }
    for(int i = 1; i < n; i++){
      scanf("%s", str);
      for(int j = 0; j < n; j++){
	mat[i][j] = str[j] - '0';
      }
    }
    
    for(int i = 0; i <= n; i++){
      sum[i][0] = 0;
      sum[0][i] = 0;
    }
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
	sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
      }
    }

    int maxS = 0;
    for(int i0 = 0; i0 <= n; i0++){
      for(int j0 = 0; j0 <= n; j0++){
	for(int i1 = i0 + 1; i1 <= n; i1++){
	  for(int j1 = j0 + 1; j1 <= n; j1++){
	    int s = sum[i1][j1] - sum[i1][j0] - sum[i0][j1] + sum[i0][j0];
	    int size = (j1 - j0) * (i1 - i0);
	    if(s == size){
	      maxS = max(maxS, s);
	    }
	  }
	}
	
      }
    }

    if(tt != 0){
      printf("\n");
    }
    printf("%d\n", maxS);
  }

  
  return 0;
}
