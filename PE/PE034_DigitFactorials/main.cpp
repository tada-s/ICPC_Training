#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fact(int n){
    if(n == 0) return 1;
    return fact(n-1)*n;
}

int getUpBound(){
    double x = 50;
    double xa = 1;
    double eps = 1e-8;
    while(abs(x - xa) > eps){
        xa = x;
        x = x - ( pow(10,x) - x * fact(9) ) / ( pow(10,x) * log(10) / log(2.71828182) - fact(9) );
    }
    return (int)pow(10, x);
}

ll getDigitFactorialSum(ll n){
    ll sum = 0;
    while(n != 0){
        sum += fact(n%10);
        n /= 10;
    }
    return sum;
}

int main(){
    int upperBound = getUpBound();
    ll sum = 0;
    for(ll i = 3; i < upperBound; i++){
        if(getDigitFactorialSum(i) == i){
            sum += i;
        }
    }
    printf("%I64d", sum);
    return 0;
}

