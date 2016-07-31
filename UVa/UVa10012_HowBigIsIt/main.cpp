#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF (1.0/0)

int factorial(int n){
    return (n == 0) ? 1 : factorial(n-1) * n;
}

int main(){
    int n, m;
    scanf("%d", &n);
    for(int nn = 0; nn < n; nn++){
        scanf("%d", &m);
        vector<double> r(m);
        vector<double> d(m);
        for(int i = 0; i < m; i++){
            float x;
            scanf("%f", &x);
            r[i] = x;
        }
        double minSize = INF;
        for(int i = 0; i < factorial(m); i++){
            for(int j = 0; j < m; j++){
                double maxX = r[j];
                for(int k = 0; k < j; k++){
                    maxX = max(maxX, d[k] + 2 * sqrt(r[j] * r[k]));
                }
                d[j] = maxX;
                }
            double size = 0;
            for(int j = 0; j < m; j++){
                size = max(size, d[j] + r[j]);
            }
            minSize = min(minSize, size);
            next_permutation(r.begin(), r.end());
        }
        printf("%.3lf\n", minSize);
    }
    return 0;
}
