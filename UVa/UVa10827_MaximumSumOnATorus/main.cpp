#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)

int mat[75 + 1][75 + 1];
int colSum[75 + 1][75 + 1];
int v[75 * 2 + 1];
int vSum[75 * 2 + 1];

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
        int n;
        scanf("%d", &n);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                scanf("%d", &mat[i][j]);
            }
        }

        for(int j = 1; j <= n; j++){
            colSum[0][j] = 0;
        }
        for(int j = 1; j <= n; j++){
            for(int i = 1; i <= n; i++){
                colSum[i][j] = colSum[i - 1][j] + mat[i][j];
            }
        }

        int maxSum = -INF;
        for(int i1 = 1; i1 <= n; i1++){
            for(int i2 = i1; i2 <= i1 + n - 1; i2++){
                v[0] = 0;
                for(int j = 1; j <= 2 * n; j++){
                    int modi1 = i1;
                    int modi2 = (i2 - 1) % n + 1;
                    int modj = (j - 1) % n + 1;
                    int sum = colSum[modi2][modj] - colSum[i1 - 1][modj];
                    if(modi2 <= i1 - 1){
                        sum += colSum[n][modj];
                    }
                    v[j] = sum;
                }

                vSum[0] = 0;
                for(int i = 1; i <= 2 * n; i++){
                    vSum[i] = vSum[i - 1] + v[i];
                }

                int maxVSum = -INF;
                multiset<int> window;
                window.insert(0);
                for(int i = 1; i <= n - 1; i++){
                    maxVSum = max(maxVSum, vSum[i] - (*window.begin()));
                    window.insert(vSum[i]);
                }
                for(int i = n; i <= 2 * n; i++){
                    maxVSum = max(maxVSum, vSum[i] - (*window.begin()));
                    window.erase(vSum[i - n]);
                    window.insert(vSum[i]);
                }

                maxSum = max(maxSum, maxVSum);
            }
        }

        printf("%d\n", maxSum);

    }

    return 0;
}
