#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int getChampernowneDigit(int n){
    ll d = 1;
    ll num = 1;
    ll pos = 1;
    ll pow10 = 10;

    while(pos + d - 1 < n){
        pos += d;
        num++;
        if(num % pow10 == 0){
            d++;
            pow10 *= 10;
        }
    }
    for(int i = 1; i < d - (n - pos); i++){
        num /= 10;
    }
    return num%10;
}

int main(){
    int p = 1;
    for(int i = 1; i <= 1000000; i *= 10){
        p *= getChampernowneDigit(i);
    }
    printf("%d",p);
    return 0;
}
