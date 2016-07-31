#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        ll h, m, s, c, time;
        ll dh, dm, ds, dc, dtime;
        c = n % 100;
        n /= 100;
        s = n % 100;
        n /= 100;
        m = n % 100;
        n /= 100;
        h = n;
        time = c + (s + (m + h * 60)* 60) * 100;

        dtime = (time * 125) / (3 * 36);
        printf("%07d\n", dtime);
    }
    return 0;
}
