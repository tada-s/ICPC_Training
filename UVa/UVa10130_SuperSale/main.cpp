#include <bits/stdc++.h>

using namespace std;
#define INF (1<<29)

int main(){
    int p[1000];
    int w[1000];
    int mw[100];
    int x[1000 * 30 + 1];


    int t;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d%d", &p[i], &w[i]);
        }

        int g;
        scanf("%d", &g);
        for(int k = 0; k < g; k++){
            scanf("%d", &mw[k]);
        }

        for(int j = 1000 * 30; j >= 0; j--){
            x[j] = -INF;
        }

        for(int i = 0; i < n; i++){
            for(int j = 1000 * 30; j >= w[i]; j--){
                x[j] = max(x[j], x[j - w[i]] + p[i]);
            }
            x[w[i]] = max(x[w[i]], p[i]);
        }

        int total = 0;
        for(int k = 0; k < g; k++){
            int maxValue = 0;
            for(int j = 0; j <= mw[k]; j++){
                maxValue = max(maxValue, x[j]);
            }
            total += maxValue;
        }

        printf("%d\n", total);

    }
    return 0;
}
