#include <bits/stdc++.h>

#define mkp make_pair

using namespace std;
int mat[500 + 1][100 + 1];
int p[500 + 1][3][2];
int main(){
    //freopen("input.txt", "r", stdin);

    int cNumber = 1;
    int n;
    int m = 0;
    scanf("%d", &n);
    while(n != 0){
        for(int i = 1; i <= n; i++){
            for(int k = 0; k < 3; k++){
                scanf("%d%d", &p[i][k][0], &p[i][k][1]);
                m = max(m, p[i][k][0]);
                m = max(m, p[i][k][1]);
            }
        }

        int lis = 0;
        int lisColor = -1;
        for(int j = 1; j <= m; j++){
            mat[0][j] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                mat[i][j] = mat[i - 1][j];
            }
            for(int k = 0; k < 3; k++){
                int c1 = p[i][k][0];
                int c2 = p[i][k][1];
                mat[i][c1] = max(mat[i][c1], mat[i - 1][c2] + 1);
                mat[i][c2] = max(mat[i][c2], mat[i - 1][c1] + 1);
                if(lis < mat[i][c1]){
                    lis = mat[i][c1];
                    lisColor = c1;
                }
                if(lis < mat[i][c2]){
                    lis = mat[i][c2];
                    lisColor = c2;
                }
            }
        }
        /*for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                printf("%d ", mat[i][j]);
            }
            putchar(10);
        }*/

        printf("%s", cNumber == 1 ? "" : "\n");
        printf("Case #%d\n", cNumber++);
        printf("%d\n", lis);
        stack< pair<int, string> > s;
        map<int, string> mString;
        mString[0] = "front";
        mString[1] = "back";
        mString[2] = "left";
        mString[3] = "right";
        mString[4] = "top";
        mString[5] = "bottom";
        for(int i = n; i >= 1; i--){
            for(int j = 1; j <= m; j++){
                for(int k = 0; k < 3; k++){
                    int c1 = p[i][k][0];
                    int c2 = p[i][k][1];
                    if(mat[i][c1] == lis && mat[i - 1][c2] == lis - 1 && c1 == lisColor){
                        s.push(mkp(i, mString[2 * k + 1]));
                        lis--;
                        lisColor = c2;

                        j = m;
                        k = 3;
                    }else if(mat[i][c2] == lis && mat[i - 1][c1] == lis - 1 && c2 == lisColor){
                        s.push(mkp(i, mString[2 * k]));
                        lis--;
                        lisColor = c1;

                        j = m;
                        k = 3;
                    }
                }
            }
        }
        while(!s.empty()){
            printf("%d %s\n", (s.top()).first, (s.top()).second.c_str());
            s.pop();
        }

        scanf("%d", &n);

    }





    return 0;
}
