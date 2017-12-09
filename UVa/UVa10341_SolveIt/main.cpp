#include <bits/stdc++.h>

using namespace std;

int p, q, r, s, t, u;

double f(double x){
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    while(scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) != EOF){
        //printf("%lf %lf\n", f(0), f(1));
        if(f(0) == 0){
            printf("%.4lf\n", 0.0);
        }else if(f(1) == 0){
            printf("%.4lf\n", 1.0);
        }else{

            double eps = 0.000000001;

            double sgn = 1;
            if(f(0) < 0 && 0 < f(1)){
                sgn = 1;
            }else if(f(1) < 0 && 0 < f(0)){
                sgn = -1;
            }else{
                printf("No solution\n");
                continue;
            }

            double lb = 0;
            double ub = 1;
            double mid;
            while(abs(lb - ub) > eps){
                mid = (lb + ub) / 2;
                if(0 < f(mid) * sgn){
                    ub = mid;
                }else{
                    lb = mid;
                }
            }

            printf("%.4lf\n", mid);
        }

    }

    return 0;
}
