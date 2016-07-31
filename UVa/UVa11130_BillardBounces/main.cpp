#include <bits/stdc++.h>

using namespace std;

#define PI (acos(0) * 2)

int main(){
    int a, b, v, angle, s;
    scanf("%d %d %d %d %d", &a, &b, &v, &angle, &s);
    while(!(a == 0 && b == 0 && v== 0 && angle == 0 && s == 0)){
        double d = v * s / (double) 2;
        double dx = d * cos(angle / (double) 180 * PI);
        double dy = d * sin(angle / (double) 180 * PI);
        int hT = (b/(double)2 + dy) / b;
        int vT = (a/(double)2 + dx) / a;
        printf("%d %d\n", vT, hT);
        scanf("%d %d %d %d %d", &a, &b, &v, &angle, &s);
    }
    return 0;
}
