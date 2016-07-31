#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define sieveUpperBound 12345678
typedef long long ll;
typedef vector<int> vi;

bitset<sieveUpperBound> bs;
vi primes;


void mksieve(){
    bs.reset();
    bs.flip();
    bs.set(0, false);
    bs.set(1, false);
    for(ll i = 2; i < sieveUpperBound; i++){
        if(bs.test(i)){
            for(ll j = i * i; j < sieveUpperBound; j += i){
                bs.set(j, false);
            }
            primes.pb(i);
        }
    }
}

bool isDecomposable(int n){
    for(int i = 0; primes[i] < n; i++){
        for(int j = 1; primes[i] + 2*j*j <= n; j++){
            if(primes[i] + 2*j*j == n) return true;
        }
    }
    return false;
}

int main(){
    mksieve();
    for(int i = 3; i < sieveUpperBound;  i += 2){
        for(int j = 3; j <= i; j += 2){
            if(!isDecomposable(i*j)){
                printf("%d",i*j);
                return 0;
            }
        }
    }
    return 0;
}
