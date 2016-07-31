#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

typedef ll number;

number f(number x){
    return (x * (x-1)) / 2;
}

int main(){
    number n, m;
    scanf("%I64d %I64d", &n, &m);
    number kmin = f(n/m) * (m - (n%m)) + f(n/m + 1) * (n%m);
    number kmax = f(n-m+1);
    printf("%I64d %I64d", kmin, kmax);
    return 0;
}
