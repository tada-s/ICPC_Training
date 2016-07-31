#include <bits/stdc++.h>

using namespace std;

#define repba(v,a,b) for(__typeof(b) v = b; v >= a; v--)

int main(){
    int cnt1, cnt2, x, y;
    scanf("%d %d %d %d",cnt1, cnt2, x, y);
    int s = (cnt1 + cnt2);
    int n = s * x * y / (x + y - 1);
    printf("%d ", (s/x) + (s/y) - (s/(x*y)));


    return 0;
}
