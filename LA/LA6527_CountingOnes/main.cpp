#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


typedef ll numero ;

numero f(numero x){
    numero uno = 1;
    return (uno<<(x-1))*x+1;
}

numero cantidadUno(numero n){
    numero s = 0, l = 0;
    numero uno = 1;
    for(int i = 0; n != 0; i++){
        if((n&1) == 1){
            s += f(i) + l;
            l += (uno << i);
        }
        n = n>>1;
    }
    return s;
}

int main(){
	#define debug 0
	#if debug
	freopen("input.txt","r",stdin);
	#endif

	numero a,b;

	while(EOF != scanf("%lld %lld", &a, &b)){
	        printf("%lld\n",cantidadUno(b) - cantidadUno(a-1));
	}


	return 0;
}


