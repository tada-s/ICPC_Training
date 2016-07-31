#include <iostream>
#include <math.h>
#include <stdio.h>
#include <bitset>
#include <vector>

using namespace std;

typedef long long ll;

ll _sieve_size;
bitset<10000010> bs;
vector<int> primes;

void sieve(long long upeerbound);

int main()
{
    int N, n, m, minM, x, k;
    sieve(10001);
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d",&n);
        minM = -1;
        for(int j = 0; j < (int) primes.size() && primes[j] < n; j++){
            k = primes[j];
            m = k * int(floor(double(n)/k));
            if(minM == -1) minM = m;
            if(m < minM){
                minM = m;
                x = j;
            }
        }
        printf("%d\n",primes[x]);
    }
    return 0;
}

void sieve(ll upperbound){
    _sieve_size = upperbound+1;
    bs.reset(); bs.flip();
    bs.set(0, false); bs.set(1, false);
    for(ll i = 2; i <= _sieve_size; i++) if(bs.test((size_t)i)){
        for(ll j = i*i; j <= _sieve_size; j+=i) bs.set((size_t)j,false);
        primes.push_back((int)i);
    }
}
