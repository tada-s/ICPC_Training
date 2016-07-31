#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
#define II ({int a; scanf("%d",&a); a;})
#define rep(v,n) for(__typeof(n) v = 0; v < n; v++)
#define all(x) x.begin(), x.end()

int main(){

	#define debug 0
	#if debug
	freopen("input.txt","r",stdin);
	#endif

	vi v;
	ll n,g;
	ll s,r,p;
	ll draw;
/*
	n = II;
	g = II;*/
    while(EOF != scanf("%lld %lld",&n,&g)){

        draw = 0;
        p = 0;

        rep(c,n){
            s = II;
            r = II;
            if(s-r > 0) p += 3;
            else if(s == r) draw++;
            else v.pb(r-s);
        }
        sort(all(v));

        if( g - draw >= 0 ){
            p = p + draw * 3;
            g = g - draw;
            draw = 0;
        }else{
            p = p + g * 3;
            draw = draw - g;
            g = 0;
            p = p + draw;
        }

        rep(c,v.size()){
            if(g == 0) break;
            if(g - v[c] - 1 >= 0){
                g = g - v[c] - 1;
                p = p + 3;
            }else if(g - v[c] == 0){
                g = g - v[c] - 1;
                p = p + 1;
            }
        }
        printf("%lld\n",p);
        if(v.size() != 0) v.clear();

       /* n = II;
        g = II;*/
    }
	return 0;
}


