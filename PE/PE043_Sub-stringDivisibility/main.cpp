#include <bits/stdc++.h>

using namespace std;

bool isSSPandigital(char number[]){
    int primes[7] = {2,3,5,7,11,13,17};
    for(int i = 0; i < 7; i++){
        int x =
        (number[i+1] - '0') * 100 +
        (number[i+2] - '0') * 10 +
        (number[i+3] - '0');
        if(x % (primes[i]) != 0) return false;
    }
    return true;
}

int main(){
    unsigned long long sum = 0;
    char number[] = "1023456789";
    char endNumber[] = "9876543210";
    while(strcmp(number,endNumber) != 0){
        if(isSSPandigital(number)){
            sum += atol(number) & 0b11111111111111111111111111111111;
        }
        next_permutation(number, number + 10);
    }
    printf("%I64d", sum);
    return 0;
}
