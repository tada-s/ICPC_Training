#include <bits/stdc++.h>

using namespace std;

int dp[6000 + 1][1000];

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n != 0){
        int w[1000];
        int mw[1000];
        for(int i = 0; i < n; i++){
            scanf("%d%d", &w[n - i - 1], &mw[n - i - 1]);
        }

        for(int i = 0; i <= 6000; i++){
            dp[i][0] = 0;
        }
        dp[w[0]][0] = 1;

        for(int j = 1; j < n; j++){
            for(int i = 0; i <= 6000; i++){
                dp[i][j] = dp[i][j - 1];
            }
            for(int i = 0; i <= mw[j]; i++){
                if((dp[i][j - 1] != 0)){
                    dp[i + w[j]][j] = max(dp[i + w[j]][j - 1], dp[i][j - 1] + 1);
                }
            }
            dp[w[j]][j] = max(dp[w[j]][j - 1], 1);
        }

        /*printf("n=%d\n",n);
        for(int i = 0; i <= 6000; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                sum += dp[i][j];
            }
            if(sum != 0){
                printf("%2d: ", i);
                for(int j = 0; j < n; j++){
                    printf("%d ", dp[i][j]);
                }
                printf("\n");
            }
        }
        printf("\n");
        printf("\n");*/

        int maxStack = 0;
        for(int i = 0; i <= 6000; i++){
            maxStack = max(maxStack, dp[i][n - 1]);
        }

        printf("%d\n", maxStack);

        scanf("%d", &n);
    }

    return 0;
}
