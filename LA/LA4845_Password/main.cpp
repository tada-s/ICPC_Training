#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef vector<int> vi;

int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
        int k;
        scanf("%d%*c", &k);
        k = k - 1;

        char m1[6][5], m2[6][5];
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 5; j++){
                scanf("%c", &m1[i][j]);
            }
            scanf("%*c");
        }
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 5; j++){
                scanf("%c", &m2[i][j]);
            }
            scanf("%*c");
        }


        vi v[5];
        for(int j = 0; j < 5; j++){
            for(int i = 0; i < 6; i++){
                for(int ii = 0; ii < 6; ii++){
                    if(m1[i][j] == m2[ii][j]){
                        v[j].pb(m1[i][j]);
                    }
                }
            }
        }

        int p[5];
        p[4] = 1;
        for(int i = 3; i >= 0; i--){
            p[i] = v[i + 1].size() * p[i + 1];
        }

        if(k < p[0] * v[0].size()){
            for(int i = 0; i < 5; i++){
                sort(v[i].begin(), v[i].end());
            }
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < v[i].size(); j++){
                    printf("%c ", v[i][j]);
                }
                putchar(10);
            }

            for(int i = 0; i < 5; i++){
                int x = k / p[i];
                printf("%c", v[i][x]);
                k = k - x * p[i];
            }
            printf(".\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
