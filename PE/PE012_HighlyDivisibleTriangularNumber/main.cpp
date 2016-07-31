#include <bits/stdc++.h>

using namespace std;

#define sieveUpperBound 10000
bitset<sieveUpperBound> bs;
vector<int> primes;

void mksieve(){
    bs.reset();
    bs.flip();
    bs.set(0,false);
    bs.set(1,false);
    for(long long i = 2; i < sieveUpperBound; i++){
        if(bs.test(i)){
            for(long long j = i * i; j < sieveUpperBound; j += i){
                bs.set(j,false);
            }
            primes.push_back(i);
        }
    }
}

int getDivisorN(int n){
    int divisorN = 1;
    int factor = 2;
    int i = 0;
    while(n != 1 && factor*factor <= n){
        int a = 1;
        while(n % factor == 0){
            n /= factor;
            a++;
        }
        divisorN *= a;
        factor = primes[++i];
    }
    if(n != 1) divisorN *= 2;
    return divisorN;
}

int main(){
    int n;
    int maxF = 0;
    int i = 1;
    mksieve();
    while(true){
        n = i * (i + 1) / 2;
        maxF = max(maxF, getDivisorN(n));
        if(maxF > 500) break;
        i++;
    }
    printf("%d", n);
    return 0;
}
