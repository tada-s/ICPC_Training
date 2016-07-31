#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt", "r", stdin);
    int c;
    scanf("%d", &c);
    for(int cc = 0; cc < c; cc++){
        if(cc != 0){
            printf("\n");
        }
        int n, h;
        scanf("%d%d", &n, &h);
        char bits[17];
        for(int i = 0; i < n - h; i++){
            bits[i] = '0';
        }
        for(int i = n - h; i < n; i++){
            bits[i] = '1';
        }
        bits[n] = '\0';

        char initialBits[17];
        strcpy(initialBits, bits);

        do{
            printf("%s\n", bits);
            next_permutation(bits, bits + n);
        }while(strcmp(initialBits, bits) != 0);
    }
    return 0;
}
