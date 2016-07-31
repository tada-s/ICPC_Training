#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define pb push_back


#define sieveUpperBound 100000
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

vi getDivisors(ll n){
    vi divisor;
    divisor.pb(1);
    int i = 0;
    ll f = primes[i];
    while(n != 1 && f*f <= n){
        int ds = divisor.size();
        ll pwf = f;
        while(n%f == 0){
            n /= f;
            for(int i = 0; i < ds; i++){
                divisor.pb( divisor[i] * pwf );
            }
            pwf *= f;
        }
        f = primes[++i];
    }
    if(n != 1){
        int ds = divisor.size();
        for(int i = 0; i < ds; i++) divisor.pb(divisor[i] * n);
    }
    sort(divisor.begin(), divisor.end());
    return divisor;
}



bool isMMPPandigital(ll n){
    vi div = getDivisors(n);
    ll sum = 0;
    int digit[10];
    for(int i = 0; i < div.size()/2; i++){
        for(int j = 0; j < 10; j++) digit[j] = 0;
        int x;
        x = n;
        while(x != 0){ digit[x%10]++; x /= 10; }
        x = div[i];
        while(x != 0){ digit[x%10]++; x /= 10; }
        x = div[div.size() - i - 1];
        while(x != 0){ digit[x%10]++; x /= 10; }
        if(digit[0] == 0){
            int j;
            for(j = 1; j < 10; j++){
                if(digit[j] != 1) break;
            }
            if(j == 10){
                return true;
            }
        }
    }
    return false;
}

int main(){
    mksieve();
    ll sum = 0;
    for(int i = 1e2; i < 1e5; i++){
        if(isMMPPandigital(i)) sum += i;
    }
    printf("%I64d", sum);
    return 0;
}
