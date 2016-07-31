#include <bits/stdc++.h>

using namespace std;


int f(int n){
    int x = n;
    int bits[32];
    for(int i = 0; i < 32; i++){
        bits[i] = x & 1;
        x = x >> 1;
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 8; j++){
            swap(bits[j + 8 * i], bits[j + 32 - 8 * (i + 1)]);
        }
    }

    for(int i = 0; i < 32; i++){
        x = x << 1;
        x = x | bits[32 - (i + 1)];
    }
    return x;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%d converts to %d\n", n, f(n));
    }

    return 0;
}
