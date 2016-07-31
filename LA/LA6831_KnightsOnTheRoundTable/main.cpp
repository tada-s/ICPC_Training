#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repab(i, a, b) for(typeof(b) i = a; i <=b ; i++)
#define pb push_back
#define mkp make_pair

typedef pair<int, int> ii;
typedef vector<ii> vii;

bitset<(int) 1e6+1> isOcupied;
bitset<(int) 1e6+1> isUsed;
bitset<(int) 1e6+1> plusOne;

int main(){
    int k, d;
    vii v;
    while(scanf("%d %d", &k, &d) != EOF){
        v.clear();
        isUsed.reset();
        isOcupied.reset();
        plusOne.reset();
        plusOne.flip();
        rep(i, d){
            int a, b;
            scanf("%d %d", &a, &b);
            isUsed.set(a, true);
            isOcupied.set(b, true);
            v.pb(mkp(a,b));
        }
        int n = 0;
        rep(i,d){
            if(!isUsed.test(v[i].second)){
                n++;
            }
        }
        rep(i,d){
            if(isOcupied.test(v[i].first)){
                plusOne.set(v[i].first, false);
            }
        }
        printf("n:%d\n", n);
        unsigned long long p = 1;
        repab(i, 1, k){
            printf("%d: %d %d\n",i, isOcupied.test(i), plusOne.test(i));
            if(!isOcupied.test(i)){
                if(plusOne.test(i)){
                    n++;
                }
                p = p * n;
                p = p % (unsigned long long)(1e9+7);
                n--;
            }
        }
        printf("%d\n", p);
    }

    return 0;
}
