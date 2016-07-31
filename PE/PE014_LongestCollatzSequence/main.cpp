#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long number;

map<number, number> dpTable;

number f(number n){
    if(dpTable.find(n) == dpTable.end()){
        if(n == 1){
            return 1;
        }else{
            number r = (n%2 == 0)? (f(n/2) + 1) : (f(3*n+1) + 1);
            dpTable[n] = r;
            return r;
        }
    }else{
        return dpTable[n];
    }
}

int main(){
    number maxChain = 0;
    number maxChainNumber = 0;
    for(int i = 1; i < 1000000; i++){
        number n = f(i);
        if(n > maxChain){
            maxChain = n;
            maxChainNumber = i;
        }
    }
    printf("%I64u", maxChainNumber);
    return 0;
}
