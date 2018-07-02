#include <bits/stdc++.h>

using namespace std;

int coin[100];
bool x[100 * 500 + 1];

int main(){
    int n;
    scanf("%d", &n);
    for(int nn = 0; nn < n; nn++){
        int m;
        scanf("%d", &m);

        if(m == 0){
            printf("0\n");
            continue;
        }

        for(int i = 0; i < m; i++){
            scanf("%d", &coin[i]);
        }

        for(int j = 0; j <= 100 * 500; j++){
            x[j] = 0;
        }

        for(int i = 0; i < m; i++){
            for(int j = 100 * 500; j >= coin[i]; j--){
                x[j] = x[j] || x[j - coin[i]];
            }
            x[coin[i]] = true;
        }

        int sum = 0;
        for(int i = 0; i < m; i++){
            sum += coin[i];
        }

        int mindiff = (1 << 29);
        for(int j = 0; j <= 100 * 500; j++){
            if(x[j]){
                int p1 = j;
                int p2 = sum - j;
                mindiff = min(mindiff, abs(p1 - p2));
            }
        }

        printf("%d\n", mindiff);

    }

    return 0;
}
