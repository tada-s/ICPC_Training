#include <bits/stdc++.h>

using namespace std;

#define sieveUpperBound 30000
bitset<sieveUpperBound> bs;
vector<int> primes;

void mksieve(){
    bs.reset();
    bs.flip();
    bs.set(0, false);
    bs.set(1, false);
    for(long long i = 2; i < sieveUpperBound; i++){
        if(bs.test(i)){
            for(long long j = i * i; j < sieveUpperBound; j += i){
                bs.set(j, false);
            }
            primes.push_back(i);
        }
    }
}

vector< pair<int, int> > factor(int n){
    vector< pair<int, int> > factors;
    int factor = 2;
    int i = 0;
    while(n != 1 && factor * factor <= n){
        if(n%factor == 0){
            int pwr = 0;
            while(n%factor == 0){
                n /= factor;
                pwr++;
            }
            factors.push_back(make_pair(factor, pwr));
        }
        factor = primes[++i];
    }
    if(n != 1) factors.push_back(make_pair(n,1));
    return factors;
}

int pwr(int b, int p){
    if(p == 0) return 1;
    int pp = pwr(b, p/2);
    if(p % 2 == 0){
        return pp * pp;
    }else{
        return pp * pp * b;
    }
}

vector<int> divisor(int n){
    vector< pair<int, int> > factors = factor(n);
    vector<int> divisors;
    divisors.push_back(1);
    for(int i = 0; i < factors.size(); i++){
        int dS = divisors.size();
        for(int j = 0; j < dS; j++){
            for(int k = 1; k <= factors[i].second; k++){
                divisors.push_back(pwr(factors[i].first, k) * divisors[j]);
            }
        }
    }
    return divisors;
}

long long divisorSum(int n){
    vector<int> div = divisor(n);
    long long sum = 0;
    for(int i = 0; i < div.size() - 1; i++){
        sum += div[i];
    }
    return sum;
}

int main(){
    mksieve();
    vector<int> v;
    bitset<28123*2> abundant2Sum;
    for(int i = 2; i <= 28123; i++){
        if(i < divisorSum(i)){
            v.push_back(i);
        }
    }
    for(int i = 0; i < v.size(); i++){
        for(int j = i; j < v.size(); j++){
            abundant2Sum.set(v[i] + v[j], true);
        }
    }

    long long sum = 0;
    for(int i = 0; i <= 28123; i++){
        if(abundant2Sum.test(i) ==  false){
            sum += i;
        }
    }
    printf("%d", sum);
    return 0;
}
