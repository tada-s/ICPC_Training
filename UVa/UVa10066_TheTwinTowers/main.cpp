#include <bits/stdc++.h>

using namespace std;

int main(){
    int n1, n2;
    int tt = 1;
    int v1[100+1];
    int v2[100+1];
    int m[100+1][100+1];

    scanf("%d %d", &n1, &n2);
    while(n1 != 0 && n2 != 0){
        for(int i = 0; i < n1; i++){
            int x;
            scanf("%d", &x);
            v1[i] = x;
        }
        for(int i = 0; i < n2; i++){
            int x;
            scanf("%d", &x);
            v2[i] = x;
        }

        for(int i = 0; i < n1; i++){
            m[i][0] = 0;
        }
        for(int i = 0; i < n2; i++){
            m[0][i] = 0;
        }

        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(v1[i-1] == v2[j-1]){
                    m[i][j] = m[i-1][j-1] + 1;
                }else{
                    m[i][j] = max(m[i-1][j], m[i][j-1]);
                }
            }
        }
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", tt++, m[n1][n2]);
        scanf("%d %d", &n1, &n2);
    }

    return 0;
}
