#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int caseN = 1;
    unsigned long long x;
    scanf("%llu", &x);
    while(x != 0){
        printf("Case %d: %lld\n", caseN++, (long long)ceil( (3.0+sqrt(9+8*x))/2.0) );
        scanf("%llu", &x);
    }
    return 0;
}
