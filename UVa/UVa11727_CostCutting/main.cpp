#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        int v[3];
        scanf("%d %d %d", v, v + 1, v + 2);
        sort(v, v + 3);
        printf("Case %d: %d\n", i, v[1]);
    }
    return 0;
}
