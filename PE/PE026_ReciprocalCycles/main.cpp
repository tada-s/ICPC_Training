#include <bits/stdc++.h>

#define EMPTY -1

using namespace std;

int v[1000];

int cycleLengthR(int n, int k){
    int nextN = (10*n) % k;

    if(nextN == 0){
        return 0;
    }
    if(v[nextN] == EMPTY){
        v[nextN] = v[n] + 1;
        return cycleLengthR(nextN, k);
    }else{
        return v[n] - v[nextN] + 1;
    }
}

int cycleLength(int n){
    for(int i = 0; i < n; i++){
        v[i] = EMPTY;
    }
    v[1] = 1;
    return cycleLengthR(1, n);
}

int main(){
    int maxL = 0;
    int maxD = 1;

    for(int d = 2; d < 1000; d++){
        int l = cycleLength(d);
        if(l > maxL){
            maxL = l;
            maxD = d;
        }
    }
    printf("%d", maxD);
    return 0;
}
