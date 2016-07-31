#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, b, p;
    scanf("%d %d %d", &n, &b, &p);
    int bottle = 0;
    int towel = n * p;
    while(n != 1){
        int aux = n;
        int k = 1;
        while(aux != 1){
            aux = aux >> 1;
            k = k << 1;
        }
        bottle += (2 * b + 1) * k / 2 ;
        n = k / 2 + (n - k);
    }
    printf("%d %d\n", bottle, towel);
    return 0;
}
