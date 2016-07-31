#include <bits/stdc++.h>

using namespace std;

#define EMPTY -1
int mat[100 + 1][100 + 1];
int dp[100 + 1][100 + 1];
int r, c;

int maxPath(int i, int j){
    if(dp[i][j] == EMPTY){
        int xx[] = {0, 0, 1, -1};
        int yy[] = {1, -1, 0, 0};
        int maxP = 0;
        for(int k = 0; k < 4; k++){
            int x = i + xx[k];
            int y = j + yy[k];
            if((0 <= x && x < r) && (0 <= y && y < c)){
                if(mat[x][y] < mat[i][j]){
                    maxP = max(maxP, maxPath(x,y));
                }
            }
        }
        dp[i][j] = maxP + 1;
    }
    return dp[i][j];
}

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d%*c", &n);
    for(int nn = 0; nn < n; nn++){
        char str[128];
        scanf("%s %d %d", str, &r, &c);

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                scanf("%d", &mat[i][j]);
            }
        }

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                dp[i][j] = EMPTY;
            }
        }

        int m = 0;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                m = max(m, maxPath(i, j));
            }
        }

        printf("%s: %d\n", str, m);
    }
}
