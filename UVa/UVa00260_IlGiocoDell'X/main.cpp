#include <bits/stdc++.h>

using namespace std;

vector<int> pset;

#define coord(x, y) ((x) + (y) * n)

void init(int n){
    pset.resize(n * n);
    for(int i = 0; i < n * n; i++){
        pset[i] = i;
    }
}

int findSet(int i){
    if(pset[i] != i){
        pset[i] = findSet(pset[i]);
    }
    return pset[i];
}

void unionSet(int i, int j){
    pset[findSet(i)] = pset[findSet(j)];
}

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    int cc = 1;
    scanf("%d%*c", &n);
    while(n != 0){
        init(n);
        char mat[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%c", &mat[i][j]);
            }
            scanf("%*c");
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int xx[] = {-1, 0, +1, -1, 0, +1};
                int yy[] = {-1, -1, 0, 0, +1, +1};
                for(int k = 0; k < 6; k++){
                    int x = xx[k] + i;
                    int y = yy[k] + j;
                    if((0 <= x && x < n) && (0 <= y && y < n)){
                        if(mat[i][j] == mat[x][y]){
                            unionSet(coord(i, j) , coord(x, y));
                        }
                    }
                }
            }
        }

        bool blackWin = false;
        for(int j = 0; j < n; j++){
            for(int j2 = 0; j2 < n; j2++){
                if(findSet(coord(0, j)) == findSet(coord(n - 1, j2))){
                    blackWin = true;
                }
            }
        }
        printf("%d %c\n", cc++, (blackWin ? 'B' : 'W'));

        scanf("%d%*c", &n);
    }
    return 0;
}
