#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define pb push_back
#define mkp make_pair
#define II ({int a; scanf("%d",&a); a;})
#define LL ({ll a; scanf("%lld",&a); a;})
#define rep(v,n) for(__typeof(n) v = 0; v < n; v++)
#define repab(v,a,b) for(__typeof(b) v = a; v <= b; v++)
#define repba(v,a,b) for(__typeof(b) v = b; v >= a; v--)
#define repstl(i,c) for(__typeof(c.begin()) i=c.begin(); i != c.end(); i++)
#define all(x) x.begin(), x.end()
#define INF 1<<29
#define EPS 1e-9



int cd[10000005];

void precalc(){
    repab(i,2,10000000/2){
        for(int j = i; j < 10000001; j+=i){
            cd[j]++;
        }
    }
}

int main(){
	#define debug 0
	#if debug
	freopen("input.txt","r",stdin);
	#endif
	precalc();
	int t = II;
	rep(tt,t){
        int n = II;
        if(n > 3161) printf("%d\n",cd[n]+2);
        else printf("%d\n",cd[n]+1);
	}
	return 0;
}












