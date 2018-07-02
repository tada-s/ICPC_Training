#include <bits/stdc++.h>

int main(){
    long long n, m, a;
    scanf("%I64d %I64d %I64d", &n, &m, &a);
    printf("%I64d", (n/a + (n%a?1:0)) * (m/a + (m%a?1:0)));
    return 0;
}
