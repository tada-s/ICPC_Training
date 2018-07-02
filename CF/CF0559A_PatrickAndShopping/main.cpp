#include <bits/stdc++.h>

using namespace std;

int main(){
    int d1, d2, d3;
    scanf("%d%d%d", &d1, &d2, &d3);
    printf("%d\n", min(d1, d2 + d3) + min(d1 + d2, d3) + min(d2, d1 + d3));
    return 0;
}
