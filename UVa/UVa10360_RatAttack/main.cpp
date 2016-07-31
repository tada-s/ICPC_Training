#include <bits/stdc++.h>

using namespace std;

int maxI, maxJ;
int ratt[1025][1025];

void explosion(int x, int y, int p, int d){
    for(int i = x - d; i <= x + d; i++){
        for(int j = y - d; j <= y + d; j++){
            if((0 <= i && i <= 1024) && (0 <= j && j <= 1024)){
                ratt[i][j] += p;
                if(ratt[i][j] > ratt[maxI][maxJ]){
                    maxI = i;
                    maxJ = j;
                }else if(ratt[i][j] == ratt[maxI][maxJ]){
                    if(i < maxI){
                        maxI = i;
                        maxJ = j;
                    }else if(i == maxI){
                        if(j < maxJ){
                            maxI = i;
                            maxJ = j;
                        }
                    }
                }
            }
        }
    }
}


int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
        int d, n;
        scanf("%d%d", &d, &n);

        maxI = 0;
        maxJ = 0;

        for(int i = 0; i <= 1024; i++){
            for(int j = 0; j <= 1024; j++){
                ratt[i][j] = 0;
            }
        }

        for(int i = 0; i < n; i++){
            int x, y, p;
            scanf("%d%d%d", &x, &y, &p);
            explosion(x, y, p, d);
        }

        printf("%d %d %d\n", maxI, maxJ, ratt[maxI][maxJ]);
    }
    return 0;
}
