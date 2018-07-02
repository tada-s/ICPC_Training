#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)

int main(){
  int b;
  scanf("%d", &b);
  for(int r = 1; r <= b; r++){
    int s;
    scanf("%d", &s);
    int n[20000 + 1];
    int sum[20000 + 1];
    for(int i = 1; i < s; i++){
      scanf("%d", &n[i]);
    }

    bool isAllNegative = true;
    for(int i = 1; i < s; i++){
      if(n[i] > 0){
	isAllNegative = false;
      }
    }
    if(isAllNegative){
      printf("Route %d has no nice parts\n", r);
    }else{
      sum[0] = 0;
      for(int i = 1; i < s; i++){
	sum[i] = sum[i - 1] + n[i];
      }

      int maxLen = -1;
      int maxSum = -INF;
      int maxi0 = -1;
      int maxi1 = -1;
      int imin = 0;
      for(int i = 1; i < s; i++){
	int cSum = sum[i] - sum[imin];
	int len = i - imin;
	if(maxSum <= cSum){
	  if((maxSum < cSum) || (maxSum == cSum && maxLen < len)){
	    maxi0 = imin;
	    maxi1 = i;
	    maxSum = cSum;
	    maxLen = len;
	  }
	}
	
	if(sum[i] < sum[imin]){
	  imin = i;
	}
      }

      printf("The nicest part of route %d is between stops %d and %d\n", r, maxi0 + 1, maxi1 + 1);
    }
  }
  return 0;
}
