#include <cstdio>
#include <cmath>

using namespace std;

double heron(double l1, double l2, double l3){
    double s = (l1 + l2 + l3) / 2;
    return sqrt(s * (s-l1) * (s-l2) * (s-l3));
}

double pie(double r, double theta){
    return r * r * theta / 2;
}

double angle(double l1, double l2, double l3){
    return acos((l2*l2 + l3*l3 - l1*l1) / (2 * l2 * l3));
}

double calcArea(double r1, double r2, double r3){
    double l1 = r2 + r3;
    double l2 = r1 + r3;
    double l3 = r1 + r2;
    double triangle = heron(l1, l2, l3);
    double pie1 = pie(r1, angle(l1,l2,l3));
    double pie2 = pie(r2, angle(l2,l1,l3));
    double pie3 = pie(r3, angle(l3,l1,l2));
    return triangle - pie1 - pie2 - pie3;
}

int main(){
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        double r1, r2, r3;
        scanf("%lf %lf %lf", &r1, &r2, &r3);
        printf("%.6lf\n", calcArea(r1, r2, r3));
    }
    return 0;
}
