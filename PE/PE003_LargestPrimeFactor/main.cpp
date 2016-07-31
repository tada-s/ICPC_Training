/*
 * Project Euler 003 - Largest prime factor
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <bits/stdc++.h>

using namespace std;

#define sieveUpperBound 776000
long long sieveSize;
vector<int> primes;

bitset<sieveUpperBound> bs;

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

vector<int> primeFactors(long long n){
    vector<int> factors;
    int i = 0;
    long long f = primes[i];
    while(n != 1 && f * f <= n){
        if(n % f == 0){
            while(n % f == 0) n = n / f;
            factors.push_back(f);
        }
        f = primes[++i];
    }
    if(n != 1) factors.push_back(n);
    return factors;
}

int main(){
    mksieve();
    vector<int> v;
    v = primeFactors(600851475143);
    printf("%d", v[v.size() - 1]);
    return 0;
}
