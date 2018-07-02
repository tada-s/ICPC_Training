#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)

int main(){
  int t;
  scanf("%d", &t);
  for(int tt = 0; tt < t; tt++){
    int y;
    scanf("%d", &y);
    int n;
    scanf("%d", &n);
    int coin[n];
    for(int i = 0; i < n; i++){
      scanf("%d", &coin[i]);
    }


    int dp[20000 + 1];
    dp[0] = 0;
    for(int i = 1; i <= 20000; i++){
      dp[i] = INF;
    }
    for(int i = 0; i < n; i++){
      for(int j = 20000; j >= coin[i]; j--){
	dp[j] = min(dp[j], dp[j - coin[i]] + 1);
      }
    }

    for(int i = y; i <= 20000; i++){
      if(dp[i] != INF){
	printf("%d %d\n", i, dp[i]);
	break;
      }
    }
    
    
  }
  
  return 0;
}
