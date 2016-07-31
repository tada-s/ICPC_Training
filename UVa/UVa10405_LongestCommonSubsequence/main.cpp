#include<stdio.h>
#include<stdlib.h>

int p[1100][1100];
int max(int x, int y);

int main(){
    freopen("input.txt", "r", stdin);
    int i, j;
    char s1[1100];
    char s2[1100];
    for(i = 0; i < 1100; i++){
        p[i][0] = p[0][i] = 0;
    }
    while(scanf("%s%s", s1 + 1, s2 + 1) != EOF){
        for(i = 1; s1[i] != '\0'; i++){
            for(j = 1; s2[j] != '\0'; j++){
                if(s1[i] == s2[j]){
                    p[i][j] = p[i - 1][j - 1] + 1;
                }else{
                    p[i][j] = max(p[i - 1][j], p[i][j - 1]);
                }
            }
        }
        printf("%d\n", p[i - 1][j - 1]);
    }
    return 0;
}
int max(int x, int y){
    if(x > y){
        return x;
    }else{
        return y;
    }
}

/*#include <bits/stdc++.h>

using namespace std;

#define EMPTY -1
int dp[1000+1][1000+1];

int lcs(char str1[], char str2[], int i, int j){
    if(i == -1 || j == -1){
        return 0;
    }

    if(dp[i][j] == EMPTY){
        if(str1[i] == str2[j]){
            dp[i][j] = lcs(str1, str2, i - 1, j - 1) + 1;
        }else{
            dp[i][j] = max(
                   lcs(str1, str2, i - 1, j),
                   lcs(str1, str2, i, j - 1)
                   );
        }
    }
    return dp[i][j];
}

int clearDP(){
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            dp[i][j] = EMPTY;
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    char str1[1000 + 2];
    char str2[1000 + 2];
    while(scanf("%s %s", str1, str2) != EOF){
        clearDP();
        printf("%d\n", lcs(str1, str2, strlen(str1) - 1, strlen(str2) - 1));
    }
    return 0;
}
*/
