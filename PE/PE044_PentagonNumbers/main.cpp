#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll p(ll n){
    return ( n * (3*n-1) ) / 2;
}

bool isPentagonal(ll n){
    int x = round( ( sqrt(24*n + 1) + 1) / 6 );
    return n == p(x);
}


int main(){
    for(int a = 2; true; a++){
        for(int b = a-1; b > 0; b--){
            if(isPentagonal(p(a) - p(b)) && isPentagonal(p(a) + p(b))){
                printf("%d", p(a) - p(b));
                return 0;
            }
        }
    }
    return 0;
}
