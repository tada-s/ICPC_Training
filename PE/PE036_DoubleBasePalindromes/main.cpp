#include <bits/stdc++.h>

using namespace std;

bool isPalindromeBase10(int n){
    int v[10];
    int i = 0;
    while(n != 0){
        v[i] = n%10;
        n /= 10;
        i++;
    }

    int length = i;
    for(i = 0; i < length/2; i++){
        if(v[i] != v[length - i - 1]){
            return false;
        }
    }

    return true;
}

bool isPalindromeBase2(int n){
    int v[64];
    int i = 0;
    while(n != 0){
        v[i] = n & 1;
        n = n >> 1;
        i++;
    }

    int length = i;
    for(i = 0; i < length/2; i++){
        if(v[i] != v[length - i - 1]){
            return false;
        }
    }

    return true;
}

typedef long long ll;

int main(){
    ll sum = 0;
    for(int i = 0; i < 1e6; i++){
        if(isPalindromeBase10(i) && isPalindromeBase2(i)){
            sum += i;
        }
    }
    printf("%d",sum);
    return 0;
}
