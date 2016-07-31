#include <cstdio>

using namespace std;

typedef unsigned long long ull;

#define EMPTY -1
ull dp[65+1][65+1];

ull f(int n, int k){
    if(dp[n][k] == EMPTY){
        if(n < k){
            dp[n][k] = 0;
        }else if(n == k || (n == 1 && k == 0)){
            dp[n][k] = 1;
        }else if(k == 0){
            ull sum = 1;
            for(int i = 0; i < n - 1; i++){
                sum += f(i, 0);
            }
            dp[n][k] = sum;
            //dp[n][k] = f(n - 1, 0) + f(n - 2, 0);
        }else{
            ull sum = f(n - 1, k - 1);
            for(int i = k; i <= n - 2; i++){
                sum += f(i, k);
            }
            dp[n][k] = sum;
            //dp[n][k] = f(n - 1, k - 1) + f(n - 1, k) - f(n - 2, k - 1) + f(n - 2, k);
        }
    }
    return dp[n][k];
}

int main(){
    for(int i = 0; i <= 65; i++){
        for(int j = 0; j <= 65; j++){
            dp[i][j] = EMPTY;
        }
    }

    int n, s;
    scanf("%d %d", &n, &s);
    while(!(n < 0 && s < 0)){
        printf("%lld\n", f(n, s));
        scanf("%d %d", &n, &s);
    }
    return 0;
}
