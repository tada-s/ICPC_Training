#include <bits/stdc++.h>

using namespace std;

#define UNDEF -1
int dp[5000][5000];
int palim[5000][5000];
char str[5001];

int isPalim(int i, int j){
    if(palim[i][j] == UNDEF){
        if(i == j || i > j){
            palim[i][j] = 1;
        }else if(str[i] == str[j]){
            palim[i][j] = isPalim(i + 1, j - 1);
        }else{
            palim[i][j] = 0;
        }
    }
    return palim[i][j];
}

int p(int i, int j){
    if(dp[i][j] == UNDEF){
        if(i > j){
            dp[i][j] = 0;
        }else if(i == j){
            dp[i][j] = 1;
        }else{
            dp[i][j] = p(i, j - 1) + p(i + 1, j) - p(i + 1, j - 1) + isPalim(i, j);
        }
    }
    return dp[i][j];
}

int main(){
    //freopen("input.txt", "r", stdin);
    for(int i = 0; i < 5000; i++){
        for(int j = 0; j < 5000; j++){
            dp[i][j] = UNDEF;
            palim[i][j] = UNDEF;
        }
    }
    scanf("%s", &str);
    int q;
    scanf("%d", &q);
    for(int k = 0; k < q; k++){
        int i, j;
        scanf("%d%d", &i, &j);
        printf("%d\n", p(i - 1, j - 1));
    }
    return 0;
}
