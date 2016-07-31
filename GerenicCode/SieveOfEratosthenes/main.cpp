#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define pb push_back


#define sieveUpperBound 500
bitset<sieveUpperBound> bs;
vi primes;

void mksieve(){
    bs.reset();
    bs.flip();
    bs.set(0, false);
    bs.set(1, false);
    for(ll i = 0; i < sieveUpperBound; i++){
        if(bs.test(i)){
            for(ll j = i * i; j < sieveUpperBound; j += i){
                bs.set(j, false);
            }
            primes.pb(i);
        }
    }
}

int main(){
    mksieve();
    printf("First %d primes \n", primes.size());
    for(int i = 0; i < primes.size(); i++){
        printf("%d\t%d\n", i+1, primes[i]);
    }
}
