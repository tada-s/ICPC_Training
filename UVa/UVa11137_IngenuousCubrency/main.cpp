#include <bits/stdc++.h>

using namespace std;

int main(){
    int cube[21];
    for(int i = 0; i < 21; i++){
        cube[i] = (i + 1) * (i + 1) *(i + 1);
    }

    long long dp[10000];
    for(int i = 0; i < 10000; i++){
        dp[i] = 1;
    }
    for(int j = 1; j < 21; j++){
        for(int i = cube[j]; i < 10000; i++){
            dp[i] = dp[i] + dp[i - cube[j]];
        }
    }

    int x;
    while(scanf("%d", &x) != EOF){
        cout << dp[x] << endl;
    }

    return 0;
}
