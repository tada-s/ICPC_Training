#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef long long ll;
typedef vector<int> vi;

#define sieveUpperBound 12345678
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

int factors(int n){
    int c = 0;
    int i = 0;
    int f = primes[i];
    while(n != 1 && f*f <= n){
        if(n%f == 0){
            while(n%f == 0){
                n/=f;
            }
            c++;
        }
        i++;
        f = primes[i];
    }
    if(n!=1) c++;
    return c;
}

int main(){
    mksieve();
    for(int i = 1; i+4 < sieveUpperBound; i++){
        if(factors(i) == 4){
            if(factors(i+1) == 4){
                if(factors(i+2) == 4){
                    if(factors(i+3) == 4){
                        printf("%d",i);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
