#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
#define II ({int a; scanf("%d",&a);a;})
#define repab(v,a,b) for(__typeof(b) v = a; v <= b; v++)

bitset<10000010> bs;
vi primes;

void sieve(ll ub){
    ll ss = ub+1;
    bs.reset(); bs.flip();
    bs.set(0,false); bs.set(1,false);
    repab(i,2,ss){
        if(bs.test((size_t)i)){
            for(ll j = i*i; j <= ss; j+=i){
                bs.set((size_t)j,false);
            }
            primes.pb((int)i);
        }
    }
}

int factors(int n){
    int f=0;
    int i=0;
    int pf = primes[i];
    while(n != 1 && (pf * pf <= n)){
        if(n%pf==0){
            f++;
            n /= pf;
        }
        while(n%pf==0) n /= pf;
        pf = primes[++i];
    }
    if(n != 1) f++;
    return f;
}

int main(){
	#define debug 0
	#if debug
	freopen("input.txt","r",stdin);
	#endif
	int n;
	sieve(1000000);
	while(n = II){
        printf("%d : %d\n",n,factors(n));
	}
	return 0;
}

