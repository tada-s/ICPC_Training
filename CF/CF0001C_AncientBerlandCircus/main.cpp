#include <bits/stdc++.h>

using namespace std;


int main(){
    pair<double, double> p1, p2, p3;
    scanf("%lf %lf", &p1.first, &p1.second);
    scanf("%lf %lf", &p2.first, &p2.second);
    scanf("%lf %lf", &p3.first, &p3.second);
    double area = (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second
                - p1.second * p2.first - p2.second * p3.first - p3.second * p1.first)/2;
    area = abs(area);
    printf("%.6lf",area);
    return 0;
}
