#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    if (n % 2 == 0) return false;
    for(int i = 3; i * i <= n; i += 2){
        if(n%i == 0) return false;
    }
    return true;
}

int getNextPermutation(int n){
    char digit[10];
    sprintf(digit, "%d", n);
    prev_permutation(digit, digit+strlen(digit));
    return atoi(digit);
}

int main(){
    int n;
    bool found = false;
    for(int i = 7; i > 0 && !found; i--){
        n = 0;
        for(int j = i; j >= 1; j--){
            n = n * 10 + j;
        }
        int upperBound = n;
        do{
            if(isPrime(n)){
                found = true;
                break;
            }
            n = getNextPermutation(n);
        } while (n != upperBound && !found);
    }
    printf("%d", n);
    return 0;
}
