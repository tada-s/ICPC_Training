#include <bits/stdc++.h>

using namespace std;

#define UNDEF -1
typedef unsigned long long number;
number dp[11][30000 + 1];
int currency[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

number change(int c, int money){
    if(c == 11 || money < 0) return 0;

    if(dp[c][money] == UNDEF){
        if(money == 0){
            dp[c][money] = 1;
        }else{
            number n = 0;
            n += change(c + 1, money);
            n += change(c, money - currency[c]);
            dp[c][money] = n;
        }
    }
    return dp[c][money];
}

int main(){
    //freopen("input.txt", "r", stdin);
    for(int i = 0 ; i < 11 ; i++){
        for(int j = 0 ; j < 30000 + 1; j++){
            dp[i][j] = UNDEF;
        }
    }
    int a, b;
    scanf("%d.%d", &a, &b);
    int money = a * 100 + b;
    while(money != 0){
        printf("%3d.%02d%17llu\n", a, b, change(0, money));
        scanf("%d.%d", &a, &b);
        money = a * 100 + b;
    }
    return 0;
}
