#include <cstdio>
#include <iostream>

using namespace std;

#define INF 1 << 29

int gcd(int a, int b){
    while(b != 0){
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int mcm(int a, int b){
    return a * b / gcd(a,b);
}

int main(){
    //freopen("input.txt", "r", stdin);
    int n, t;
    scanf("%d %d", &n, &t);
    while(!(n == 0 && t == 0)){
        int coin[50];
        int table[10];
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            coin[i] = x;
        }
        for(int i = 0; i < t; i++){
            int x;
            scanf("%d", &x);
            table[i] = x;
        }

        for(int tt = 0; tt < t; tt++){
            int minusDelta = INF;
            int plusDelta = INF;
            for(int a = 0; a < n; a++){
                for(int b = a + 1; b < n; b++){
                    for(int c = b + 1; c < n; c++){
                        for(int d = c + 1; d < n; d++){
                            int m = mcm( mcm(coin[a],coin[b]), mcm(coin[c],coin[d]));
                            int k = table[tt] / m;
                            minusDelta = min(minusDelta, table[tt] - m*k);
                            plusDelta = min(plusDelta, m*(k+1) - table[tt]);
                            if(table[tt] % m == 0){
                                minusDelta = 0;
                                plusDelta = 0;
                            }
                        }
                    }
                }
            }
            printf("%d %d\n", table[tt] - minusDelta, table[tt] + plusDelta);
        }
        scanf("%d %d", &n, &t);
    }
}
