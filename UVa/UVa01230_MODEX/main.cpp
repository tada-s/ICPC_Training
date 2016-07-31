#include <bits/stdc++.h>

using namespace std;

int pwr(int x, int y, int n){
    if (y == 0) return 1;
    int p = pwr(x, y/2, n) % n;
    if(y % 2 == 0){
        return (p * p) % n;
    }else{
        return (((p * p) % n)* x) % n;
    }
}

int main(){
    int c;
    scanf("%d", &c);
    for(int i = 0; i < c; i++){
        int x, y, n;
        scanf("%d %d %d", &x, &y, &n);
        printf("%d\n", pwr(x,y,n));
    }
    return 0;
}
