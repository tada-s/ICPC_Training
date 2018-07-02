#include <bits/stdc++.h>

using namespace std;

#define repba(v,a,b) for(__typeof(b) v = b; v >= a; v--)

int main(){
    int n, k;
    scanf("%d %d",&n, &k);

    repba(i,k+2,n){
        printf("%d ",i);
    }
    int sgn = 1;
    int x = k + 1;
    printf("%d ",x);
    repba(i,1,k){
        x = x - i * sgn;
        sgn = -sgn;
        printf("%d ",x);
    }
    return 0;
}
