#include <stdio.h>
#include <bitset>
#include <vector>
#include <algorithm>
#include <strings.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef vector<int> vi;

#define sieveUpperBound (int) 1e4
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
            if(i > 1e3) primes.pb(i);
        }
    }
}

bool isPrime(int n){
    int l = 0;
    int u = primes.size();
    while(l <= u){
        int m = (l+u)/2;
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

bool arePermutation(int a, int b, int c){
    char str1[10];
    char str2[10];
    char str3[10];
    sprintf(str1,"%d",a);
    sprintf(str2,"%d",b);
    sprintf(str3,"%d",c);
    sort(str1, str1 + strlen(str1));
    sort(str2, str2 + strlen(str2));
    sort(str3, str3 + strlen(str3));
    return strcmp(str1, str2) == 0 && strcmp(str2, str3) == 0;
}

int main(){
    mksieve();
    for(int i = 0; i < primes.size(); i++){
        for(int j = i+1; j < primes.size(); j++){
            int x = 2 * primes[j] - primes[i];
            if(!(primes[i] == 1487 && primes[j] == 4817)){
                if(isPrime(x) && arePermutation(primes[i],primes[j],x)){
                    printf("%d%d%d",primes[i],primes[j],x);
                    return 0;
                }
            }
        }
    }
    return 0;
}

