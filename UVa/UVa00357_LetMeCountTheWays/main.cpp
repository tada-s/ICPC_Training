#include <bits/stdc++.h>

using namespace std;

int main(){
    long long dp[30000 + 1];
    int coins[5] = {1, 5, 10, 25, 50};
    for(int j = 0; j <= 30000; j++){
        dp[j] = 1;
    }
    for(int i = 1; i < 5; i++){
        int coinValue = coins[i];
        for(int j = 0; j < coinValue; j++){
            dp[j] = dp[j];
        }
        for(int j = coinValue; j <= 30000; j++){
            dp[j] = dp[j] + dp[j - coinValue];
        }
    }

    int n;
    while(scanf("%d", &n) != EOF){
        if(dp[n] == 1){
            cout << "There is only 1 way to produce " << n << " cents change.\n";
        }else{
            cout << "There are " << dp[n] << " ways to produce " << n << " cents change.\n";
        }
    }
    return 0;
}
