#include <bits/stdc++.h>

using namespace std;

#define EMPTY (-1)
int dp[21][21];

int lis(int i, int j, vector<int> &v){
    if(dp[i][j] == EMPTY){
        int s = 0;
        if(i == 0 || j == 0){
            s = (v[i] == j) ? 1 : 0;
        }else{
            if(v[i] == j){
                s = max(s, lis(i - 1, j - 1, v) + 1);
            }else{
                s = max(lis(i - 1, j, v), lis(i, j - 1, v));
            }
        }
        dp[i][j] = s;
    }
    return dp[i][j];
}

int main(){
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    bool flagEOF = false;
    while(!flagEOF){
        vector<int> m(n + 1);
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            m[x] = i;
        }

        int nextInt;
        char nextChar;
        while(true){
            flagEOF = (scanf("%d%c", &nextInt, &nextChar) == EOF);
            if(nextChar == '\n' || flagEOF){
                n = nextInt;
                break;
            }

            vector<int> v(n);
            v[0] = m[nextInt];
            for(int i = 1; i < n; i++){
                int x;
                scanf("%d", &x);
                v[i] = m[x];
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dp[i][j] = EMPTY;
                }
            }

            for(int i = 0; i < v.size(); i++){
                printf("%d ", v[i]);
            }
            putchar(10);
            for(int i = 0; i < m.size(); i++){
                printf("%d ", m[i]);
            }
            putchar(10);

            printf("%d\n", lis(n - 1, n - 1, v));
            v.clear();
        }
        m.clear();
    }
    return 0;
}
