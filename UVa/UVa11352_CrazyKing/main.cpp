#include <bits/stdc++.h>

using namespace std;

int hx[8] = {1,2,2,1,-1,-2,-2,-1};
int hy[8] = {2,1,-1,-2,-2,-1,1,2};

int kx[8] = {-1,0,1,1,1,0,-1,-1};
int ky[8] = {1,1,1,0,-1,-1,-1,0};

#define mkp make_pair
typedef pair<int, int> ii;

int m, n;
int mat[100+1][100+1];
int sX, sY, tX, tY;

#define WALL -99
#define EMPTY 0

bool isOnBoard(int x, int y){
    return (0 <= x && x < m && 0 <= y && y < n);
}

int sssp(){
    int minPath = 0;
    queue<ii> q;
    q.push(mkp(sX, sY));
    while(!q.empty()){
        ii p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        minPath = mat[x][y];
        if(x == tX && y == tY){
            return minPath;
        }else{
            for(int i = 0; i < 8; i++){
                int nx = x + kx[i];
                int ny = y + ky[i];
                if(isOnBoard(nx, ny) && mat[nx][ny] == EMPTY){
                    mat[nx][ny] = minPath + 1;
                    q.push(mkp(nx, ny));
                }
            }
        }
    }
    return -1;
}

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
    scanf("%d %d\n", &m, &n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            mat[i][j] = EMPTY;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            char c;
            scanf("%c", &c);
            //printf("[%c]", c);
            switch(c){
            case 'Z':
                mat[i][j] = WALL;
                for(int k = 0; k < 8; k++){
                int nx = i + hx[k];
                int ny = j + hy[k];
                if(isOnBoard(nx, ny)){
                mat[nx][ny] = WALL;
                }
                }
                break;
            case 'A':
                sX = i;
                sY = j;
                break;
            case 'B':
                tX = i;
                tY = j;
                break;
                case '.':
                break;
            }
        }
        scanf("%*c");
        //putchar(10);
    }
    mat[sX][sY] = EMPTY;
    mat[tX][tY] = EMPTY;
    int mintrip = sssp();
    if(mintrip == -1){
        printf("King Peter, you can't go now!\n");
    }else{
        printf("Minimal possible length of a trip is %d\n", mintrip);
    }

    }
    return 0;
}
