#include <bits/stdc++.h>

using namespace std;

int main(){
    int dp[7489 + 1];
    for(int i = 0; i <= 7489; i++){
        dp[i] = 1;
    }
    int coins[5] = {1, 5, 10, 25, 50};
    for(int i = 1; i < 5; i++){
        for(int j = coins[i]; j <= 7489; j++){
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }

    int n;
    while(scanf("%d", &n) != EOF){
        printf("%d\n", dp[n]);
    }

    return 0;
}
