#include <bits/stdc++.h>

using namespace std;

int f(int d, int i){
    int x = 0;
    i = (i - 1) % (1 << d);
    for(int k = 0; k < d - 1; k++){
        x = (x << 1) + (i & 1);
        i = i >> 1;
    }
    return (1 << (d - 1)) + x;
}

int main(){
    int l;
    scanf("%d", &l);
    for(int ll = 0; ll < l; ll++){
        int d, i;
        scanf("%d%d", &d, &i);
        printf("%d\n", f(d, i));
    }
    return 0;
}
