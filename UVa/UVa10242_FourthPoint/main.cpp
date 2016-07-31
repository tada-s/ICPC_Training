#include <cstdio>
#include <utility>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    pair<double, double> p[4];
    double x,y;
    while(scanf("%lf %lf", &x, &y) != EOF){
        p[0].first = x;
        p[0].second = y;
        for(int i = 1; i < 4; i++){
            scanf("%lf %lf", &x, &y);
            p[i].first = x;
            p[i].second = y;
        }
        if(p[0] == p[3]){
            swap(p[2], p[3]);
        }else if(p[1] == p[2]){
            swap(p[0], p[1]);
        }else if(p[1] == p[3]){
            swap(p[0], p[1]);
            swap(p[2], p[3]);
        }
        double dx = (p[3].first - p[2].first) + (p[1].first - p[0].first);
        double dy = (p[3].second - p[2].second) + (p[1].second - p[0].second);
        x = p[0].first + dx;
        y = p[0].second + dy;
        printf("%.3lf %.3lf\n", x, y);
    }
    return 0;
}
