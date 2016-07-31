#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define EMPTY -1
ll dp[10000 + 1];

int getNonZeroDigit(ll n){
    if(dp[n] == EMPTY){
        ll x = getNonZeroDigit(n - 1) * n;
        while(x % 10 == 0){
            x /= 10;
        }
        dp[n] = x % 1000000;
    }
    return dp[n];
}

void init(){
    for(int i = 0; i <= 10000; i++){
        dp[i] = EMPTY;
    }
    dp[0] = 1;
}

int main(){
    init();
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%5d -> %d\n", n, getNonZeroDigit(n)%10);
    }

    return 0;
}
