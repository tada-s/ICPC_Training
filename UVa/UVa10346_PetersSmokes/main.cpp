#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll m, ll k){
    if(m < k) return 0;
    else{
        return (m/k) + f((m/k) + (m%k), k);
    }
}

int main(){
    ll n, k;
    while(scanf("%lld %lld", &n, &k) != EOF){
        printf("%lld\n", f(n*k, k));
    }
    return 0;
}
