#include <cstdio>
#include <utility>
using namespace std;

int sign(int n){
    return (n > 0) - (n < 0);
}

int acw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
    int x1 = p2.first - p1.first;
    int y1 = p2.second - p1.second;
    int x2 = p2.first - p3.first;
    int y2 = p2.second - p3.second;
    return x1*y2 - x2*y1;
}

bool isConvex(pair<int, int> p[], int n){
    int s = sign(acw(p[0], p[1], p[2]));
    for(int i = 0; i < n; i++){
        if(sign(acw(p[i],p[(i+1)%n],p[(i+2)%n])) != s){
            return false;
        }
    }
    return true;
}

int main(){
    //freopen("input.txt","r", stdin);
    pair<int, int> p[50];
    int n;
    scanf("%d", &n);
    while(n != 0){
        for(int i = 0; i < n; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            p[i].first = x;
            p[i].second = y;
        }
        if(isConvex(p, n)){
            printf("No\n");
        }else{
            printf("Yes\n");
        }
        scanf("%d", &n);
    }
    return 0;
}
