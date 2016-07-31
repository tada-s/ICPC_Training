#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(c,n) for(__typeof(n) c = 0; c < n; c++)


map<ll, ll> table;

ll f(ll n, ll k){

    if(n < k) return 1;
    else{
        if(table.find(n) == table.end()){
            ll aux = (f(n - 1, k) + f(n - k, k)) % 1000000007;
            table[n] = aux;
            return aux;
        }else{
            return table[n];
        }
    }
}

int main(){
    ll t,k,a,b;
    scanf("%I64d %I64d", &t, &k);
    rep(tt,t){
        scanf("%I64d %I64d",&a,&b);
        ll fa = f(a+k-1,k);
        ll fb = f(b+k,k);
        ll s = (fb >= fa) ? fb-fa : fb - fa + 1000000007;
        printf("%I64d\n", s);
    }
    return 0;
}
