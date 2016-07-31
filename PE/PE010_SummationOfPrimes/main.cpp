/*
 * Project Euler 010 - Summation Of Primes
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 */

#include <bits/stdc++.h>

using namespace std;

#define sieveUpperBound 2001000
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
                bs.set(j, false);
            }
            primes.push_back(i);
        }
    }
}

int main(){
    unsigned long long sum = 0;
    mksieve();
    int i = 0;

    while(primes[i] < 2000000){
        sum = sum + primes[i];
        i++;
    }
    printf("%I64d",sum);
    return 0;
}
