#include <stdio.h>
#include <algorithm>
#include <bitset>
#include <vector>

using namespace std;

#define pb push_back
typedef long long ll;
typedef vector<int> vi;

#define sieveUpperBound (int) 1e6
bitset<sieveUpperBound> bs;
vi primes;

void mksieve(){
    bs.reset();
    bs.flip();
    bs.set(0, false);
    bs.set(1, false);
    for(ll i = 2; i < sieveUpperBound; i++){
        if(bs.test(i)){
            for(ll j = i*i; j < sieveUpperBound; j+=i){
                bs.set(j, false);
            }
            primes.pb(i);
        }
    }
}
/*
bool isPrime(int n){
    return binary_search(primes.begin(), primes.end(), n);
}

int getLongetCPrime(){
    int sum = 0;
    vi s(primes.size()+1);
    s[0] = 0;
    for(int i = 0; i < primes.size(); i++){
        sum += primes[i];
        s[i+1] = sum;
    }
    for(int i = 0; i < s.size(); i++){
        int delta = s.size() - i - 1;
        for(int j = 0; j <= i; j++){
            if(isPrime(s[j+delta] - s[j])){
                        printf("%d\n", delta);
                return s[j+delta] - s[j];
            }
        }
    }
}
*/
int getLongestC(int n){
    int l = 0;
    int u = 0;
    int sum = primes[0];

    while(sum != n){
        if(sum < n){
            u++;
            sum += primes[u];
        }else if(sum > n){
            sum -= primes[l];
            l++;
        }
    }
    return u-l+1;
}

int main(){
    int maxP = 0;
    int maxL = 0;

    mksieve();

    for(int i = 0; i < primes.size(); i++){
        int l = getLongestC(primes[i]);
        if(l > maxL){
            maxL = l;
            maxP = primes[i];
        }
    }

//    printf("%d", getLongetCPrime());
    printf("%d %d", maxL, maxP);
    return 0;
}
