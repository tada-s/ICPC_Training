#include <bits/stdc++.h>

using namespace std;

#define EMPTY -1

long long dp[50 + 1];

long long  f(int n){
    long long  a = 0;
    long long  b = 1;
    for(int i = 0; i < n; i++){
        long long  c = b;
        b = a + b;
        a = c;
    }
    return b;
}

int main(){
    for(int i = 0; i < 50 + 1; i++){
        dp[i] = EMPTY;
    }

    int x;
    scanf("%d", &x);
    while(x != 0){
        printf("%lld\n", f(x));
        //cout << f(x);
        scanf("%d", &x);
    }
    return 0;
}
