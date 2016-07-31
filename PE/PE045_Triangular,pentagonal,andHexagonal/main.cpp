#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll p(ll n){
    return (n*(3*n-1))/2;
}

ll h(ll n){
    return n*(2*n-1);
}

bool isPentagonal(ll n){
    ll x = round((sqrt(24*n + 1) + 1) / 6);
    return n == p(x);
}


int main(){
    int i = 143 + 1;
    while(true){
        if( isPentagonal(h(i)) ){
            printf("%d", h(i));
            break;
        }
        i++;
    }
    return 0;
}
