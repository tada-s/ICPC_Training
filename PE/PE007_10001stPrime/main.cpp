/*
 * Project Euler 007 - 10001st prime
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 * What is the 10001st prime number?
 */

#include <bits/stdc++.h>

using namespace std;

#define sieveUpperBound 105000
long long sieveSize;
vector<int> primes;

bitset<sieveUpperBound> bs;

void mksieve(){
    bs.reset();
    bs.flip();
    bs.set(0,false);
    bs.set(1,false);
    for(size_t i = 2; i < sieveUpperBound; i++){
        if(bs.test(i)){
            for(size_t j = i * i; j < sieveUpperBound; j += i){
                bs.set(j, false);
            }
            primes.push_back((int) i);
        }
    }
}

double ln(int n){ return log(n);}

int main(){
    mksieve();
    printf("%d",primes[10001-1]);
    return 0;
}
