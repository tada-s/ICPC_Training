#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll a,b,c;
    scanf("%I64d %I64d %I64d", &a, &b, &c);
    ll m=0;
    m = max(m, a+b+c);
    m = max(m, a*b+c);
    m = max(m, a+b*c);
    m = max(m, a*b*c);
    m = max(m, (a+b)*c);
    m = max(m, a*(b+c));
    printf("%d",m);
    return 0;
}
