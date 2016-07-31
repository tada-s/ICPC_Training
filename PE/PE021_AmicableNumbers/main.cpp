#include <bits/stdc++.h>

using namespace std;

typedef long long number;

#define sieveUpperBound 1000
bitset<sieveUpperBound> bs;
vector<int> primes;

void mksieve(){
    bs.reset();
    bs.flip();
    bs.set(0,false);
    bs.set(1,false);
    for(long long i = 2; i < sieveUpperBound; i++){
        if(bs.test(i)){
            for(long long j = i * i; j < sieveUpperBound; j += i){
                bs.set(j,false);
            }
            primes.push_back(i);
        }
    }
}

vector< pair<int, int> > factor(int n){
    vector< pair<int, int> > factors;
    factors.push_back(make_pair(1,1));
    long long factor = 2;
    int i = 0;
    while(n != 1 && factor*factor <= n){
        if(n % factor == 0){
            int pwr = 0;
            while(n % factor == 0){
                n /= factor;
                pwr++;
            }
            factors.push_back(make_pair(factor, pwr));
        }
        factor = primes[++i];
    }
    if(n != 1) factors.push_back(make_pair(n, 1));
    return factors;
}

long long power(int n, int pwr){
    if(pwr == 0) return 1;
    long long p = power(n, pwr / 2);
    if(pwr%2 == 0){
        return p * p;
    }else{
        return p * p * n;
    }
}

vector<int> divisor(int n){
    vector< pair<int, int> > factors = factor(n);
    vector<int> divisors;
    divisors.push_back(1);
    for(int i = 1; i < factors.size(); i++){
        int dSize = divisors.size();
        for(int j = 0; j < dSize; j++){
            for(int k = 1; k <= factors[i].second; k++){
                divisors.push_back(power(factors[i].first, k) * divisors[j]);
            }
        }
    }
    sort(divisors.begin(), divisors.end());

    return divisors;
}

long long d(int n){
    vector<int> dv = divisor(n);
    long long sum = 0;
    for(int i = 0; i < dv.size() - 1; i++){
        sum += dv[i];
    }
    return sum;
}

int main(){
    mksieve();
    map<int, int> m;
    for(int i = 3; i < 50001; i++){
        m[i] = d(i);
    }

    long long sum = 0;
    for(int i = 3; i < 10000; i++){
        if(m[i] != i){
            if(m[ m[i] ] == i){
                sum += i;
            }
        }
    }
    printf("%I64d",sum);

    return 0;
}
