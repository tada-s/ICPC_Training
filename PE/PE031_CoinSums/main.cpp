#include <bits/stdc++.h>

using namespace std;

#define coinN 8
int coin[coinN] = {1, 2, 5, 10, 20, 50, 100, 200};

int calcCombR(int n, int c){
    if(c == coinN) return 0;

    int sum = 0;
    while(n > 0){
        sum += calcCombR(n,c+1);
        n -= coin[c];
    }
    if(n == 0) sum++;
    return sum;
}

int calcComb(int n){
    return calcCombR(n, 0);
}

int main(){
    printf("%d", calcComb(200));
    return 0;
}
