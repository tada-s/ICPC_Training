#include <bits/stdc++.h>

using namespace std;

int main(){
  int v[10000 + 1];
  int sum[10000 + 1];
  
  
  int n;
  scanf("%d", &n);
  while(n != 0){
    for(int i = 1; i <= n; i++){
      scanf("%d", &v[i]);
    }

    bool isAllNegative = true;
    for(int i = 1; i <= n; i++){
      if(0 < v[i]){
	isAllNegative = false;
      }
    }

    if(isAllNegative){
      printf("Losing streak.\n");
    }else{
      sum[0] = 0;
      for(int i = 1; i <= n; i++){
	sum[i] = sum[i - 1] + v[i];
      }

      int minpos = 0;
      int maxSum = -(1<<29);
      for(int i = 1; i <= n; i++){
	maxSum = max(maxSum, sum[i] - sum[minpos]);
	if(sum[i] < sum[minpos]){
	  minpos = i;
	}
      }

      printf("The maximum winning streak is %d.\n", maxSum);
    }
    
    scanf("%d", &n);
  }
  return 0;
}
