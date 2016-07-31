#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    int h, u, d, f;
    scanf("%d %d %d %d", &h, &u, &d, &f);
    while(h != 0){
        int x = 0;
        int day = 1;
        h *= 100;
        u *= 100;
        d *= 100;
        int r = u * f / 100;
        while(true){
            if(u > 0){
                x += u;
                u = u - r;
            }
            if(x > h){
                printf("success on day %d\n", day);
                break;
            }
            x -= d;
            if(x < 0){
                printf("failure on day %d\n", day);
                break;
            }
            day++;
        }
        scanf("%d %d %d %d", &h, &u, &d, &f);
    }
    return 0;
}
