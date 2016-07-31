#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    long long l, h;
    scanf("%ld%ld", &l, &h);
    while(!(l == 0 && h == 0)){
        printf("%ld\n", h/5 - l/5 + 1);
        scanf("%ld%ld", &l, &h);
    }
    return 0;
}
