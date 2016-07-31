#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef long long ll;
typedef vector<int> vi;

#define sieveUpperBound 1000000
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
    int u = primes.size()-1;
    int l = 0;
    while(l <= u){
        int m = (u + l) / 2;
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

bool isCircularPrime(int n){
    char digits[10];
    sprintf(digits, "%d", n);
    int l = strlen(digits);

    for(int i = 0; i < l; i++){
        int x = 0;
        x = atoi(digits);
        if(!isPrime(x)) return false;
        for(int j = 0; j < l-1; j++){
            swap(digits[j], digits[j+1]);
        }
    }

    return true;
}

int main(){
    int c = 0;
    mksieve();
    for(int i = 0; i < primes.size(); i++){
        if(isCircularPrime(primes[i])){
            c++;
        }
    }
    printf("%d", c);
    return 0;
}
