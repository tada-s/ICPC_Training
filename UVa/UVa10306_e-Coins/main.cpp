#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)

int main(){
    int space[300 + 1][300 + 1];
    int cvalue[40];
    int ivalue[40];

    int n;
    scanf("%d", &n);
    for(int nn = 0; nn < n; nn++){
        int m, s;
        scanf("%d%d", &m, &s);

        for(int i = 0; i < m; i++){
            scanf("%d%d", &cvalue[i], &ivalue[i]);
        }

        for(int x = 0; x <= s; x++){
            for(int y = 0; y <= s; y++){
                space[x][y] = INF;
            }
        }

        space[0][0] = 0;
        for(int i = 0; i < m; i++){
            for(int x = 0; x <= s; x++){
                for(int y = 0; y <= s; y++){
                    int x2 = x - cvalue[i];
                    int y2 = y - ivalue[i];
                    if((0 <= x2 && x2 <= s) && (0 <= y2 && y2 <= s)){
                        space[x][y] = min(space[x][y], space[x2][y2] + 1);
                    }
                }
            }
        }

        int smallestSolution = INF;
        for(int x = 0; x <= s; x++){
            for(int y = 0; y <= s; y++){
                if(x * x + y * y == s * s && space[x][y] != INF){
                    smallestSolution = min(smallestSolution, space[x][y]);
                }
            }
        }

        if(smallestSolution == INF){
            printf("not possible\n");
        }else{
            printf("%d\n", smallestSolution);
        }

    }

}
