#include <bits/stdc++.h>
using namespace std;
#define II ({int a; scanf("%d",&a);a;})
#define rep(v,n) for(__typeof(n) v = 0; v < n; v++)

int main(){
	#define debug 0
	#if debug
	freopen("input.txt","r",stdin);
	#endif
	int t = II;
	rep(i,t){
        int g = II;
        int l = II;
        if(l%g==0) printf("%d %d\n",g,l);
        else printf("-1\n");
	}
	return 0;
}
