#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef long long ll;
typedef vector<int> vi;

#define sieveUpperBound 1234567
bitset<sieveUpperBound> bs;
vi primes;

void mksieve(){
    bs.reset();
    bs.flip();
    bs.set(0, false);
    bs.set(1, false);
    for(ll i = 2; i < sieveUpperBound; i++){
        if(bs.test(i)){
            for(ll j = i*i; j < sieveUpperBound; j += i){
                bs.set(j, false);
            }
            primes.pb(i);
        }
    }
}

bool isPrime(int n){
    int u = primes.size() - 1;
    int l = 0;
    while(l <= u){
        int m = (l + u) / 2;
        if(n < primes[m]){
            u = m - 1;
        }else if(n > primes[m]){
            l = m + 1;
        }else{
            return true;
        }
    }
    return false;
}

bool isTruncatablePrime(int n){
    if(!isPrime(n)) return false;
    int f = 10;
    while( n / f != 0 ){
        if(!isPrime(n / f)) return false;
        if(!isPrime(n % f)) return false;
        f *= 10;
    }
    return true;
}

int main(){
    mksieve();
    int sum = 0;
    for(int i = 4; i < primes.size(); i++){
        if(isTruncatablePrime(primes[i])){
            sum += primes[i];
        }
    }
    printf("%d", sum);
    return 0;
}
