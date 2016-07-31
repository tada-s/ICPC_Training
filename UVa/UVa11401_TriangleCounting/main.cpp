#include <stdio.h>
//using namespace std;

int main()
{
    long long int n, r;
    bool b;
    scanf("%lld", &n);
    while(n >= 3){/*
        r = 0;
        b = false;
        for(int i = 3; i <= n; i++){
            if(b){
                r += (i-2)*(i-2)/4;
            }else{
                r += (i-3)*(i-1)/4;
            }
            b = !b;
        }*/
        r = (2*n*n*n-9*n*n+13*n)/24;
        r -= (n+1)/8;
        printf("%lld\n", r);
        scanf("%lld", &n);
    }
    return 0;
}
