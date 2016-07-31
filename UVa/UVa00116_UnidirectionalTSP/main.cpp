#include <bits/stdc++.h>

using namespace std;

#define INF (((ll)1)<<50 - 1)
typedef long long ll;
typedef vector<int> vi;
//vi path;
queue<int> q;
int m, n;

ll dist[100][100];
ll mat[100][100];
ll father[100][100];

int generateShortestPath(){
    for(int r = 0; r < m; r++){
        dist[r][0] = mat[r][0];
    }
    for(int c = 0; c < n; c++){
        for(int r = 0; r < m; r++){
            for(int i = -1; i <= 1; i++){
                int nr = (r + i + m) % m;
                int nc = c + 1;
                if(mat[nr][nc] + dist[r][c] == dist[nr][nc]){
                    if(r < father[nr][nc]){
                        dist[nr][nc] = mat[nr][nc] + dist[r][c];
                        father[nr][nc] = r;
                    }
                }
                if(mat[nr][nc] + dist[r][c] < dist[nr][nc]){
                    dist[nr][nc] = mat[nr][nc] + dist[r][c];
                    father[nr][nc] = r;
                }
            }
        }
    }


    int minI = 0;
    for(int i = 1; i < m; i++){
        if(dist[i][n - 1] < dist[minI][n - 1]){
            minI = i;
        }
    }

    for(int i = n - 1; i >= 0; i--){
        q.push(minI);
        minI = father[minI][i];
    }

}

int main(){
//freopen("input.txt", "r", stdin);
    while(scanf("%d %d", &m, &n) != EOF){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ll x;
                scanf("%I64d", &x);
                mat[i][n - j - 1] = x;
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = INF;
                father[i][j] = INF;
            }
        }
        generateShortestPath();
/*
printf("\nmat:\n");
for(int i = 0; i < m; i++){
for(int j = 0; j < n; j++){
printf("%2d ", mat[i][j]);
}
putchar(10);
}
printf("\n\ndist:\n");
for(int i = 0; i < m; i++){
for(int j = 0; j < n; j++){
printf("%2d ", dist[i][j]);
}
putchar(10);
}
printf("\n\nfather:\n");
for(int i = 0; i < m; i++){
for(int j = 0; j < n; j++){
if(j == 0) printf(" - ");
else printf("%2d ", father[i][j]);
}
putchar(10);
}
//*/
        int x = q.front();
        q.pop();
        int aux = x;
        while(!q.empty()){
            printf("%d ", x + 1);
            x = q.front();
            q.pop();
        }
        printf("%d\n%I64d\n", x + 1, dist[aux][n - 1]);
    }
    return 0;
}
