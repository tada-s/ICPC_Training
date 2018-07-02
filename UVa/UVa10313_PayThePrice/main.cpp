#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // constraint vs value
    long long dp[300 + 1][300 + 1];
    for(int i = 0; i <= 300; i++){
        for(int j = 0; j <= 300; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(int k = 1; k <= 300; k++){
        for(int i = 1; i <= 300; i++){
            for(int j = max(i, k); j <= 300; j++){
                dp[i][j] = dp[i][j] + dp[i - 1][j - k];
            }
        }
    }

    char str[128];
    while(scanf("%[^\n]%*c", str) != EOF){
        int a, b, c;
        int i0, i1, n;
        if(sscanf(str, "%d%d%d", &a, &b, &c) == 3){
            i0 = b;
            i1 = c;
            n = a;
        }else if(sscanf(str, "%d%d", &a, &b) == 2){
            i0 = 0;
            i1 = b;
            n = a;
        }else{
            sscanf(str, "%d", &a);
            i0 = 0;
            i1 = a;
            n = a;
        }
        long long sum = 0;
        for(int i = i0; i <= min(i1, n); i++){
            sum += dp[i][n];
        }
        cout << sum << endl;

    }

    return 0;
}
