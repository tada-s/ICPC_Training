#include <bits/stdc++.h>

using namespace std;
#define pb push_back
typedef vector<int> vi;
typedef long long ll;


#define sieveUpperBound 150000
bitset<sieveUpperBound> bs;
vi primes;

void mksieve(){
    bs.reset();
    bs.flip();
    bs.set(0,false);
    bs.set(1,false);
    for(ll i = 0; i < sieveUpperBound; i++){
        if(bs.test(i)){
            for(ll j = i*i; j < sieveUpperBound; j += i){
                bs.set(j,false);
            }
            primes.pb(i);
        }
    }
}

ll p(int x, int a, int b){
    return x*(x + a) + b;
}

bool isPrime(ll n){
    int a = 0;
    int b = primes.size() - 1;
    while(a <= b){
        int m = (a+b)/2;
        if(n < primes[m]){
            b = m - 1;
        }else if(n > primes[m]){
            a = m + 1;
        }else{
            return true;
        }
    }
    return false;
}

int main(){
    int a, b;
    ll maxN = 0;
    ll maxA = 0;
    ll maxB = 0;

    mksieve();
    for(int i = 0; primes[i] < 1000; i++){
        b = primes[i];
        for(int j = 0; b - primes[j] - 1 < 1000; j++){
            a = b - primes[j] - 1;
            if(a > -1000){
                ll n;
                for(n = 0; isPrime( p(n,a,b) ); n++);
                if(n > maxN){
                    maxA = a;
                    maxB = b;
                    maxN = n;
                }
            }
        }
    }
    printf("%I64d", maxA * maxB);
    return 0;
}
